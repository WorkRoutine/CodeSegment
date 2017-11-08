/*
 * Usage option:
 * gcc main.c -o a
 * ./a -f input.c -o output.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

/* global opetaion */

/* read operation */
static operation_read;
/* write operation */
static operation_write;
/* dump all */
static operation_all;
/* external file */
static operation_file;

#define SYS_OFFSET "/sys/devices/platform/gmac0/net/eth0/eeprom_index"
#define SYS_LENGTH "/sys/devices/platform/gmac0/net/eth0/eeprom_length"
#define SYS_EEPROM "/sys/devices/platform/gmac0/net/eth0/eeprom"

/* 
 * hex string to dec string 
 * - '0x10' --> '16'
 * - '10' ----> '10'
 * - '07' ----> '7' (not support)
 */
int string_to_dec(char *string)
{
    int value;
    char *tmp;

    /* hex to dec */
    if (strstr(string, "0x") != NULL || strstr(string, "0X") != NULL) {
        tmp = string + 2;
        sscanf(tmp, "%x", &value);
    } else { /* dec string to int */
        sscanf(string, "%d", &value);
    }
    return value;
}

/* setup offset of register */
static int setup_offset(int value)
{
    int fd;

    fd = open(SYS_OFFSET, O_RDWR);
    if (fd < 0) {
        printf("failed to setup offset for register.\n");
        return -ENODEV;
    }
    write(fd, &value, sizeof(int));
    close(fd);
    return 0;
}

/* get current offset of register */
static int get_offset(void)
{
    int fd;
    int value;

    fd = open(SYS_OFFSET, O_RDWR);
    if (fd < 0) {
        printf("failed to get offset for register.\n");
        return -ENODEV;
    }
    read(fd, &value, sizeof(char));
    close(fd);
    return value;
}


/* setup length of register */
static int setup_length(int value)
{
    int fd;

    fd = open(SYS_LENGTH, O_RDWR);
    if (fd < 0) {
        printf("failed to setup offset for register.\n");
        return -ENODEV;
    }
    write(fd, &value, sizeof(char));
    close(fd);
    return 0;
}

/* get current offset of register */
static int get_length(void)
{
    int fd;
    int value;

    fd = open(SYS_LENGTH, O_RDWR);
    if (fd < 0) {
        printf("failed to get offset for register.\n");
        return -ENODEV;
    }
    read(fd, &value, sizeof(char));
    close(fd);
    return value;
}
/*
 * Read a register value.
 */
static int read_one_register(int offset)
{
    int fd;
    int value;

    /* setup offset for register */
    setup_offset(offset);
    /* setup length for register */
    setup_length(1);

    /* read from /sys/... */
    fd = open(SYS_EEPROM, O_RDWR);
    if (fd < 0) {
        printf("failed to open eeprom.\n");
        return -ENODEV;
    }
    read(fd, &value, sizeof(unsigned short));
    close(fd);
    return value;
}

void usage(const char *program_name) 
{
    printf("%s 1.0.0(2017-10-16)\n", program_name);
    printf("This is a program read/write data on 88E6321 with i2c bus\n");
    printf("Usage: Write binary data to 88E6321.\n");
    printf("      %s -w -f <filename> -x <start_address> [-s <write size>]\n",
                  program_name);
    printf("Usage: Write data to a register on 88e6321.\n");
    printf("      %s -w -d <data> -x <start_address>\n", program_name);
    printf("Usage: Read data from a register on 88e6321.\n");
    printf("      %s -r -x <start_address>\n", program_name);
    printf("Usage: Read serial data from register on 88e6321.\n");
    printf("      %s -r -x <start_address> -s <read size>\n", program_name);
    printf("Usage: Read all data from reigster on 88e6321.\n");
    printf("      %s -r -a\n", program_name);
}

int main(int argc,char *argv[]) 
{
    char *file_name   = NULL;
    char *offset      = NULL;
    char *size        = NULL;
    char *data        = NULL;

    const char *short_opts = "hrwabl:x:f:s:d:";
    const struct option long_opts[] = {
	{"help",no_argument,NULL,'h'},
	{"file",required_argument,NULL,'f'},
	{"read",no_argument,NULL,'r'},
	{"write",no_argument,NULL,'w'},
	{"all",no_argument,NULL,'a'},
	{"size",required_argument,NULL,'s'},
	{"data",required_argument,NULL,'d'},
	{"offset",required_argument,NULL,'b'},
	{0,0,0,0}
    };
    int hflag = 0;
    int c;
    opterr = 0;
    
    while((c = getopt_long(argc,argv,short_opts,long_opts,NULL)) != -1) {
	switch(c) {
	    case 'h':
		hflag = 1;
		break;
            case 'r':
                operation_read = 1;
                break;
            case 'w':
                operation_write = 1;
                break;
            case 'a':
                operation_all = 1;
                break;
	    case 'f':
		file_name = optarg;
                operation_file = 1;
		break;
	    case 's':
		size = optarg;
		break;
	    case 'd':
		data = optarg;
		break;
	    case 'x':
		offset = optarg;
		break;
	    case '?':
		if(optopt == 'f' || optopt == 's' || optopt == 'd' || optopt == 'x')
		    printf("Error:option -%c requires an argument\n",optopt);
		else if(isprint(optopt))
		    printf("Error:unknow option '-%c'\n",optopt);
		else
		    printf("Error:unknow option character '\\x%x\n'",optopt);
		return 1;
	    default:
		abort();
	}
    }
    
    if(hflag || argc == 1) {
	usage(argv[0]);
	return 0;
    }

    /* read operation */
    if (operation_read) {
        /* read one register */
        if (!size) {
            int value;
            int reg = 0;
            
            /* cover string to int */
            value = string_to_dec(offset);
            reg   = read_one_register(value);

            printf("88E6321: EEPRM[%#8x] value[%#8x]\n", value, reg);
            return 0;
        } else { /* read serial registers */
            ;
        }

    }
    return 0;
}

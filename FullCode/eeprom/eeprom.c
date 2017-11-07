/*
 * EEPROM demo code on userspace
 * (C) 2017.10 <buddy.zhang@aliyun.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <stdarg.h>
#include <string.h>

#include <linux/i2c.h>
#include <linux/i2c-dev.h>

/* EEPROM MAPPING */
#define EEPROM_MAC_START        0x00
#define EEPROM_IP_START         0x06
#define EEPROM_NETMASK_START    0x0A
#define EEPROM_GATWAY_START     0x0E
#define EEPROM_DNS_START        0x12
#define EEPROM_DNS1_START       0x16
#define EEPROM_DHCP_FLAG        0x1A
#define EEPROM_GATWARY_FLAG     0x1B
#define EEPROM_DNS_FLAG         0x1C
#define EEPROM_APP_DEVICE_FLAG  0x1D
#define EEPROM_NTP_FLAG         0x1E
#define EEPROM_NTP1_IP_START    0x20
#define EEPROM_NTP2_IP_START    0x24
#define EEPROM_APP_URL_START    0x28


/* I2C bus */
#define I2C_DEV_CHIP            "/dev/i2c-0"

#define I2C_M_WR                0

/* i2c device handler */
static unsigned int i2c_fd;

/* i2c slave address */
static unsigned int i2c_slave_addr = 0x50;

/* MAC address */
#define MAC_LEN                 0x6
static unsigned char aup_mac[MAC_LEN];

/* -v to display more information */
static unsigned int aup_debug_v;

/* read command line */
#define READ_CMD_LEN            0x12
static const char *aup_read_cmd[READ_CMD_LEN] = { "mac", "ip", "netmask", "gw", "dns", "dns2",
                                "with_dhcp", "with_gw", "with_dns", "with_dns2",
                                "start_dev", "with_ntp", "ntp", "ntp2", "app_url", "ip_sh"};

#define WRITE_CMD_LEN           0x12
/* write command line */
static const char *aup_write_cmd[WRITE_CMD_LEN] = { "mac", "ip", "netmask", "gw", "dns",
                                "dns2", "with_dhcp", "with_gw", "with_dns", "with_dns2",
                                "start_dev", "with_ntp", "ntp", "ntp2", "app_url"};

/* argument list */
static char *aup_argument_list[6];

/* read format function */
typedef void (*do_read_func_t)(void);

/* write format function */
typedef void (*do_write_func_t)(void);

static void aup_read_mac(void);
static void aup_read_ip(void);
static void aup_read_netmask(void);
static void aup_read_gatway(void);
static void aup_read_dns(void);
static void aup_read_dns2(void);
static void aup_read_with_dhcp(void);
static void aup_read_with_gw(void);
static void aup_read_with_dns(void);
static void aup_read_with_dns2(void);
static void aup_read_start_dev(void);
static void aup_read_with_ntp(void);
static void aup_read_ntp(void);
static void aup_read_ntp2(void);
static void aup_read_app_url(void);
static void aup_read_ip_sh(void);

/* do read function array */
do_read_func_t do_read_array[] = { aup_read_mac,         aup_read_ip, 
                                   aup_read_netmask,     aup_read_gatway, 
                                   aup_read_dns,         aup_read_dns2,
                                   aup_read_with_dhcp,   aup_read_with_gw,
                                   aup_read_with_dns,    aup_read_with_dns2,
                                   aup_read_start_dev,   aup_read_with_ntp,
                                   aup_read_ntp,         aup_read_ntp2,
                                   aup_read_app_url,     aup_read_ip_sh};

static void aup_write_mac(void);
static void aup_write_ip(void);
static void aup_write_netmask(void);
static void aup_write_gatway(void);
static void aup_write_dns(void);
static void aup_write_dns2(void);
static void aup_write_with_dhcp(void);
static void aup_write_with_gw(void);
static void aup_write_with_dns(void);
static void aup_write_with_dns2(void);
static void aup_write_start_dev(void);
static void aup_write_with_ntp(void);
static void aup_write_ntp(void);
static void aup_write_ntp2(void);
static void aup_write_app_url(void);

/* do write function array */
do_write_func_t do_write_array[] = { aup_write_mac,         aup_write_ip,
                                     aup_write_netmask,     aup_write_gatway,
                                     aup_write_dns,         aup_write_dns2,
                                     aup_write_with_dhcp,   aup_write_with_gw,
                                     aup_write_with_dns,    aup_write_with_dns2,
                                     aup_write_start_dev,   aup_write_with_ntp,
                                     aup_write_ntp,         aup_write_ntp2,
                                     aup_write_app_url,     NULL};

/*
 * Specify logcat via 'aup_debug_v'
 * @fmt: format string
 * @...: argument list
 */
void aup_debug(const char *fmt, ...)
{
    if (!aup_debug_v)
        return;
    else {
        va_list ap;
        va_start(ap, fmt);
        vfprintf(stdout, fmt, ap);
        va_end(ap);
    }
}

/*
 * I2C read
 * @fd: file handler
 * @addr: i2c slave 7-bit address
 * @offset: read position.
 * @buf: buffer for reading data.
 * @len: length for reading.
 *
 * @return: the number of i2c_msg has read. 
 *          succeed is 2.
 */
static int I2CBus_packetRead(int fd, unsigned char addr, unsigned char offset, 
                             unsigned char *buf, unsigned char len)
{
    unsigned char tmpaddr[2];
    struct i2c_msg msgs[2];
    struct i2c_rdwr_ioctl_data msgset;
    int rc;

    tmpaddr[0]     = offset;
    msgs[0].addr   = addr & 0xfe;
    msgs[0].flags  = I2C_M_WR;
    msgs[0].len    = 1;
    msgs[0].buf    = tmpaddr;

    msgs[1].addr   = addr & 0xfe;
    msgs[1].flags  = I2C_M_RD;  ;
    msgs[1].len    = len;
    msgs[1].buf    = buf;

    msgset.msgs    = msgs;
    msgset.nmsgs   = 2;

    rc = ioctl(fd, I2C_RDWR, &msgset);
    return rc;
}

/* 
 * I2C write
 * @fd: file handler.
 * @addr: i2c slave 7-bit address
 * @offset: write position
 * @buf: buffer for writuing data.
 * @len: the length for writing
 *
 * @return: the number of i2c_msg has write.
 *          succeed is 1.
 */
static int I2CBus_packetWrite(int fd, unsigned char addr, unsigned char offset,
                              unsigned char *buf, unsigned char len)
{
    unsigned char tmpaddr[2];
    struct i2c_msg msgs[2];
    struct i2c_rdwr_ioctl_data msgset;
    int rc;

    tmpaddr[0]     = offset;
    tmpaddr[1]     = buf[0];
    msgs[0].addr   = addr & 0xfe;
    msgs[0].flags  = I2C_M_WR;
    msgs[0].len    = 2;
    msgs[0].buf    = tmpaddr;

    msgset.msgs    = msgs;
    msgset.nmsgs   = 1;

    rc = ioctl(fd, I2C_RDWR, &msgset); 
    return rc;
}


/* open i2c slave device */
static open_i2c_device(void)
{
    i2c_fd = open(I2C_DEV_CHIP, O_RDWR);
    if (i2c_fd < 0) {
        aup_debug("ERROR: fail to open %s\n", I2C_DEV_CHIP);
        exit(1);
    }
}

/* exit i2c slave device */
static close_i2c_device(void)
{
    close(i2c_fd);
}

/* read i2c common function */
static void aup_read_common(int fd, unsigned char addr, unsigned char offset,
                              unsigned char *buf, unsigned char len)
{
    int err;
    int i;

    for (i = 0; i < len; i++) {
        int local_offset = offset + i;

        err = I2CBus_packetRead(fd, addr, local_offset, &buf[i], 1);
        if (err != 2) {
            aup_debug("Can't read data from %02x\n", local_offset);
            exit(1);
        }
    }
}

/* write i2c common function */
static void aup_write_common(int fd, unsigned char addr, unsigned char offset,
                             unsigned char *buf, unsigned char len)
{
    int err;
    int i;

    for (i = 0; i < len; i++) {
        int local_offset = offset + i;

        err = I2CBus_packetWrite(fd, addr, local_offset, &buf[i], 1);
        usleep(4000);
        if (err != 1) {
            aup_debug("Can't write data to %02x\n", local_offset);
            exit(1);
        }
    }
}

/*
 * parse read operation
 * @string: argument string
 */
static void parse_read_operation(const char *string)
{
    int i;

    for (i = 0; i < READ_CMD_LEN; i++) {
        if (strcmp(string, aup_read_cmd[i]) == 0) {
            do_read_array[i]();
            if (strcmp(string, "ip_sh") != 0)
                printf("\n");
            return;
        }
    }
    aup_debug("ERROR: can't find read command.\n");
    exit(1);
}

/*
 * parse write operation
 * @string: argument string
 */
static void parse_write_operation(const char *string)
{
    int i;

    for (i = 0; i < WRITE_CMD_LEN; i++) {
        if (strcmp(string, aup_write_cmd[i]) == 0) {
            do_write_array[i]();
            return;
        }
    }
    aup_debug("ERROR: can't find read command.\n");
    exit(1);
}

/* dump format ip address */
void dump_ip_address(unsigned char *buf, int len, int reversal)
{
    int i;

    for (i = 0; i < len; i++) {
        if (reversal)
            printf("%d", buf[i]);
        else
            printf("%d", buf[len - i - 1]);
        if (i != (len - 1))
            printf(".");
    }
}

/* dump format boolean */
void dump_boolean(unsigned char value, int max)
{
    if (value < 0 || value > max) {
        aup_debug("Invalue boolean value.\n");
        exit(1);
    }
    if (value)
        printf("1");
    else
        printf("0");
}

/* dump format mac address */
void dump_mac_address(unsigned char *buf, int len, int reversal)
{
    int i;

    for (i = 0; i < len; i++) {
        if (reversal)
            printf("%02x", buf[i]);
        else
            printf("%02x", buf[len - i - 1]);
        if (i != (len - 1))
            printf(":");
    }
}

/* truncate array */
void truncate_array(unsigned char *a, int len)
{
    unsigned char buf[20];
    int i;
    
    for (i = 0; i < len; i++)
        buf[i] = a[len - i -1];
    for (i = 0; i < len; i++)
        a[i] = buf[i];
}

/* parse mac address */
void parse_mac_address(unsigned char *mac)
{
    int i, j;
    int pos[8];
    int value;

    if (!aup_argument_list[0]) {
        printf("ERROR: empty mac address.\n");
        exit(1);
    }

    if (strchr(aup_argument_list[0], ':') == NULL) {
        for (i = 0; i < 6; i++)
            sscanf(aup_argument_list[i], "%x", (unsigned int *)(unsigned long)(
                                               ((unsigned char *)mac + i)));
        return;
    }

    memset(pos, 0, 8);
    for (i = 0, j = 0; i < strlen(aup_argument_list[0]); i++)
        if (aup_argument_list[0][i] == ':')
            pos[++j] = i + 1;
    pos[++j] = strlen(aup_argument_list[0]) + 1;

    for (i = 0; i < j; i++) {
        char buf[6];
        int length = pos[i + 1] - pos[i] - 1;

        strncpy(buf, (unsigned char *)aup_argument_list[0] + pos[i], length);
        buf[length] = '\0';

        sscanf(buf, "%x", (unsigned int *)(unsigned long)(
                          ((unsigned char *)mac + i)));
    }
}

/* parse ip address */
void parse_ip_address(unsigned char *ip)
{
    int i, j;
    int pos[8];
    int value;

    if (!aup_argument_list[0]) {
        aup_debug("ERROR: empty mac address.\n");
        exit(1);
    }

    memset(pos, 0, 8);
    for (i = 0, j = 0; i < strlen(aup_argument_list[0]); i++)
        if (aup_argument_list[0][i] == '.')
            pos[++j] = i + 1;
    pos[++j] = strlen(aup_argument_list[0]) + 1;

    for (i = 0; i < j; i++) {
        char buf[6];
        int length = pos[i + 1] - pos[i] - 1;

        strncpy(buf, aup_argument_list[0] + pos[i], length);
        buf[length] = '\0';

        sscanf(buf, "%d", (unsigned int *)(unsigned long)(
                          ((unsigned char *)ip + i)));
    }
}

/****** write basic function ******/

/* write file data to eeprom */
static void aup_file_write(const char *file)
{
    int fd;
    int i, err;
    char buf[128];

    fd = open(file, O_RDONLY);
    if (fd < 0) {
       aup_debug("ERROR: can't open file %s\n", file);
       exit(1);
    }

    read(fd, buf, 128);
    for (i = 0; i < 128; i++) {
        err = I2CBus_packetWrite(i2c_fd, i2c_slave_addr, i, &buf[i], 1);
        usleep(5000);
        if (err != 1) {
            aup_debug("ERROR: can't delivered message on i2c.\n");
            exit(1);
        }
    }
    close(fd);
}

/* Write URL to EEPROM */
static void aup_write_app_url(void)
{
    int err;
    int i;
    int offset = EEPROM_APP_URL_START;
    char buf[64];
    char *args = aup_argument_list[0];

    strcpy(buf, args);

    err = strlen(args);
    buf[err] = '\0';

    for (i = err + 1; i < 64; i++)
        buf[i] = 0xff;
    err = 0;

    for (i = 0; i < 64; i++) {
        char tmp = buf[i];
        int _offset = offset + i;


        err = I2CBus_packetWrite(i2c_fd, i2c_slave_addr,
                                 _offset, &tmp, 1);
        usleep(8000);
        if (err != 1) {
            printf("Can't write URL to eeprom.\n");
            exit(1);
        }
    }
}

/* write ntp2 */
static void aup_write_ntp2(void)
{
    unsigned char buf[8];

    /* parse ntp2 from command line */
    parse_ip_address(buf);
    truncate_array(buf, 4);

    /* write ntp2 into eeprom */
    aup_write_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_NTP2_IP_START, buf, 4);
}

/* write ntp */
static void aup_write_ntp(void)
{
    unsigned char buf[8];

    /* parse ntp from command line */
    parse_ip_address(buf);
    truncate_array(buf, 4);

    /* write ntp into eeprom */
    aup_write_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_NTP1_IP_START, buf, 4);
}

/* write with_ntp */
static void aup_write_with_ntp(void)
{
    unsigned char buf[16];

    /* parse with ntp from command line */
    sscanf(aup_argument_list[0], "%d", (unsigned int *)(unsigned long)&buf[0]);

    /* write with ntp into eeprom */
    aup_write_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_NTP_FLAG, buf, 1);
}

/* write start_dev */
static void aup_write_start_dev(void)
{
    unsigned char buf[16];

    /* parse start dev from command line */
    sscanf(aup_argument_list[0], "%d", (unsigned int *)(unsigned long)&buf[0]);

    /* write start dev into eeprom */
    aup_write_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_APP_DEVICE_FLAG, buf, 1);
}

/* write with dns2 */
static void aup_write_with_dns2(void)
{
    unsigned char buf[16];

    /* parse with dns2 from command line */
    sscanf(aup_argument_list[0], "%d", (unsigned int *)(unsigned long)&buf[0]);

    /* write with dns2 into eeprom */
    aup_write_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_DNS_FLAG, buf, 1);
}

/* write with dns */
static void aup_write_with_dns(void)
{
    unsigned char buf[16];

    /* parse with dns from command line */
    sscanf(aup_argument_list[0], "%d", (unsigned int *)(unsigned long)&buf[0]);

    /* write with dns into eeprom */
    aup_write_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_DNS_FLAG, buf, 1);
}

/* write with_gw */
static void aup_write_with_gw(void)
{
    unsigned char buf[16];

    /* parse with gw from command line */
    sscanf(aup_argument_list[0], "%d", (unsigned int *)(unsigned long)&buf[0]);

    /* write with gw into eeprom */
    aup_write_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_GATWARY_FLAG, buf, 1);
}

/* Write with_dhcp */
static void aup_write_with_dhcp(void)
{
    unsigned char buf[16];

    /* parse with dhcp from command line */
    sscanf(aup_argument_list[0], "%d", (unsigned int *)(unsigned long)&buf[0]);

    /* write with dhcp into eeprom */
    aup_write_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_DHCP_FLAG, buf, 1);
}

/* Write dns2 */
static void aup_write_dns2(void)
{
    unsigned char buf[8];

    /* parse dns2 from command line */
    parse_ip_address(buf);
    truncate_array(buf, 4);

    /* write dns2 into eeprom */
    aup_write_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_DNS1_START, buf, 4);
}

/* write dns */
static void aup_write_dns(void)
{
    unsigned char buf[8];

    /* parse dns from command line */
    parse_ip_address(buf);
    truncate_array(buf, 4);

    /* write dns into eeprom */
    aup_write_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_DNS_START, buf, 4);
}

/* write gatway */
static void aup_write_gatway(void)
{
    unsigned char buf[8];

    /* parse gatway from command line */
    parse_ip_address(buf);
    truncate_array(buf, 4);

    /* write gatway into eeprom */
    aup_write_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_GATWAY_START, buf, 4);
}

/* write netmask */
static void aup_write_netmask(void)
{
    unsigned char buf[8];

    /* parse netmask from command line */
    parse_ip_address(buf);
    truncate_array(buf, 4);

    /* write netmask into eeprom */
    aup_write_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_NETMASK_START, buf, 4);
}

/* write IP */
static void aup_write_ip(void)
{
    unsigned char buf[8];

    /* parse ip from command line */
    parse_ip_address(buf);
    truncate_array(buf, 4);

    /* write ip into eeprom */
    aup_write_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_IP_START, buf, 4);
}

/* write MAC address */
static void aup_write_mac(void)
{
    unsigned char buf[80];

    /* parse mac from command line */
    parse_mac_address(buf);
    truncate_array(buf, 6);

    /* write mac into eeprom */
    aup_write_common(i2c_fd, i2c_slave_addr,
                     (unsigned char)EEPROM_MAC_START, buf, 6); 
}


/****** read basic function ******/

/* read app_url */
static void aup_read_app_url(void)
{
    int i;
    int err;
    int offset = EEPROM_APP_URL_START;
    char buf[64];
    char url_buf[64];

    for (i = 0; i < 64; i++) {
        int _offset = offset + i;

        /* read netmask from eeprom */
        err = I2CBus_packetRead(i2c_fd, i2c_slave_addr,
                                _offset, &buf[i], 1);
        if (err != 2) {
            aup_debug("ERROR: can't read IP.\n");
            exit(1);
        }
        usleep(8000);
    }

    /* dmplicate character to url buffer */
    for (i = 0; i < 64; i++) {
        if (buf[i] == '\0' || buf[i] == 0xFF)
            break;
        else 
            url_buf[i] = buf[i];
    }
    url_buf[i] = '\0';
    /* dump url information */
    printf("%s", url_buf);
}

/* read ntp2 */
static void aup_read_ntp2(void)
{
    char buf[4];

    /* read ntp2 from eeprom */
    aup_read_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_NTP2_IP_START, buf, 4);

    /* format print ntp2 string */
    dump_ip_address(buf, 4, 0);
}

/* read ntp */
static void aup_read_ntp(void)
{
    char buf[4];

    /* read ntp from eeprom */
    aup_read_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_NTP1_IP_START, buf, 4);

    /* format print ntp string */
    dump_ip_address(buf, 4, 0);
}

/* read with_ntp */
static void aup_read_with_ntp(void)
{
    char buf;

    /* read NTP service from eeprom */
    aup_read_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_NTP_FLAG, &buf, 1);

    /* dump boolean value */
    dump_boolean(buf, 2);
}

/* read start_dev */
static void aup_read_start_dev(void)
{
    char buf;

    /* read start device from eeprom */
    aup_read_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_APP_DEVICE_FLAG, &buf, 1);

    /* dump boolean value */
    dump_boolean(buf, 1);
}

/* read with dns2 */
static void aup_read_with_dns2(void)
{
    printf("READ with_dns2\n");
}

/* read with dns */
static void aup_read_with_dns(void)
{
    char buf;

    /* read dns from eeprom */
    aup_read_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_DNS_FLAG, &buf, 1);

    /* dump boolean value */
    dump_boolean(buf, 2);
}

/* read with_gw */
static void aup_read_with_gw(void)
{
    char buf;

    /* read gatway from eeprom */
    aup_read_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_GATWARY_FLAG, &buf, 1);

    /* dump boolean value */
    dump_boolean(buf, 1);
}

/* Read with_dhcp */
static void aup_read_with_dhcp(void)
{
    char buf;

    /* read dhcp boolean from eeprom */
    aup_read_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_DHCP_FLAG, &buf, 1);
    
    /* dump boolean value */
    dump_boolean(buf, 1);
}

/* Read dns2 */
static void aup_read_dns2(void)
{
    char buf[4];

    /* read dns2 from eeprom */
    aup_read_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_DNS1_START, buf, 4);

    /* format print dns string */
    dump_ip_address(buf, 4, 0);
}

/* Read dns */
static void aup_read_dns(void)
{
    char buf[4];

    /* read dns from eeprom */
    aup_read_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_DNS_START, buf, 4);

    /* format print dns string */
    dump_ip_address(buf, 4, 0);
}

/* Read gatway */
static void aup_read_gatway(void)
{
    char buf[4];

    /* read gatway from eeprom */
    aup_read_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_GATWAY_START, buf, 4);

    /* format print gatway string */
    dump_ip_address(buf, 4, 0);
}

/* Read netmask */
static void aup_read_netmask(void)
{
    char buf[4];

    /* read netmask from eeprom */
    aup_read_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_NETMASK_START, buf, 4);

    /* format print netmask string */
    dump_ip_address(buf, 4, 0);
}

/* Read IP */
static void aup_read_ip(void)
{
    char buf[4];

    /* read ip address from eeprom */
    aup_read_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_IP_START, buf, 4);

    /* format print ip string */
    dump_ip_address(buf, 4, 0);
}

/* Read manage IP */
static void aup_read_manage_ip(void)
{
    char buf[4];

    /* read ip address from eeprom */
    aup_read_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_IP_START, buf, 4);

    buf[0] = 0xFE;
    /* format print ip string */
    dump_ip_address(buf, 4, 0);
}

/* Read MAC address */
static void aup_read_mac(void)
{
    char buf[6];

    /* read mac address from eeprom */
    aup_read_common(i2c_fd, i2c_slave_addr,
                    (unsigned char)EEPROM_MAC_START, buf, 6);

    /* format print mac string */
    dump_mac_address(buf, 6, 0);
}

/* 
 * Read ip_sh 
 * Format:
 * | ip address | app_url | netmask | gatway | dns | dns1 | mang_ip | ntp |
 */
static void aup_read_ip_sh(void)
{
    /* ip address */
    aup_read_ip();
    printf(" ");
    /* app_url */
    aup_read_app_url();
    printf(" ");
    /* netmask */
    aup_read_netmask();
    printf(" ");
    /* gatway */
    aup_read_gatway();
    printf(" ");
    /* dns */
    aup_read_dns();
    printf(" ");
    /* dns1 */
    aup_read_dns2();
    printf(" ");
    /* mang_ip */
    aup_read_manage_ip();
    printf(" ");
    /* ntp */
    aup_read_ntp();
    printf("\n");
}

/* user help message */
void usage(const char *program_name) 
{
    printf("%s 1.0.0(2017-10-16)\n",program_name);
    printf("AuperaStor EEPROM\n");
    printf("Usage:%s [-t N[s]] [-T N[s]] [-F] DEV\n\n",
		program_name);
    printf("Periodically write to watchdog device DEV\n\n");
    printf("       -T N    Reboot after N seconds if not reset (default 60)\n");
    printf("       -t N    Reset every N seconds (default 30)\n");
    printf("       -F      Run in foreground\n");
    printf("       -r      Reboot system after timeout\n");
}

int main(int argc,char *argv[]) 
{
    char *option_read  = NULL;
    char *option_write = NULL;
    char *option_file  = NULL;
 
    unsigned int option_foreground = 1;
    const char *short_opts = "hvw:r:F:f:";
    const struct option long_opts[] = {
	{"help", no_argument, NULL, 'h'},
	{"Foreground", no_argument, NULL, 'F'},
	{"display", no_argument, NULL, 'v'},
	{"read", required_argument, NULL, 'r'},
	{"write", required_argument, NULL, 'w'},
	{"file", required_argument, NULL, 'f'},
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
        case 'v':
            aup_debug_v = 1;
            break;
        case 'w':
            option_write = optarg;
            aup_argument_list[0] = argv[optind];
            aup_argument_list[1] = argv[optind + 1];
            aup_argument_list[2] = argv[optind + 2];
            aup_argument_list[3] = argv[optind + 3];
            aup_argument_list[4] = argv[optind + 4];
            aup_argument_list[5] = argv[optind + 5];
            break;    
        case 'r':
            option_read = optarg;
            break;
        case 'F':
            option_foreground = 0;
            break;
        case 'f':
            option_file = optarg;
            break;
        case '?':
            if(optopt == 't' || optopt == 'T')
                aup_debug("Error:option -'%c' requires an argument.\n", optopt);
            else if(isprint(optopt))
                aup_debug("Error:unknow option '-%c'\n",optopt);
            else
                aup_debug("Error:unknow option character '\\x%x\n'",optopt);
            exit(1);
        default:
            abort();
        }
    }
    
    if(hflag) {
        usage(argv[0]);
	return 0;
    }

    /* open i2c device */
    open_i2c_device();

    /* Forward running ? */
//    if (!option_foreground)
  //      daemon(1, 1);

    /* read operation */
    if (option_read) {
        parse_read_operation(option_read);
    }

    /* write operation */
    if (option_write) {
        parse_write_operation(option_write);
    }

    /* write binary to eeprom */
    if (option_file) {
        aup_file_write(option_file);
    }
    /* close i2c device */
    close_i2c_device();
    return 0;
}

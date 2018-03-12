/*
 * EERPOM utils on MGT2600/Aup
 * (C) 2018.03 <buddy.zhang@aliyun.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <command.h>

void usage(const char *program_name)
{
    int i;

    printf("%s 1.1.1(2018.03.12)\n", program_name);
    for (i = 0; aup_cmd_list[i].cmdline; i++) {
        printf("[%d]%s\n", i, aup_cmd_list[i].cmdline);
        printf("    [usage]    ");
        printf(aup_cmd_list[i].usage, program_name);
        printf("\n    [Describe] %s\n", aup_cmd_list[i].desc);
    }
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

    while((c = getopt_long(argc, argv, short_opts, long_opts,NULL)) != -1) {
        switch(c) {
        case 'h':
            hflag = 1;
            break;
        case 'v':
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
            break;
        case 'f':
            break;
        case '?':
            if(optopt == 't' || optopt == 'T')
                ;
            else if(isprint(optopt))
                ;
            else
                ;
            exit(1);
        default:
            abort();
        }
    }
    if (hflag) {
        usage(argv[0]);
        return 0;
    }

    /* Open I2C-0 */
    open_i2c_device();

    if (option_read) {
        read_common_entry(option_read);
    }

    if (option_write) {
        write_common_entry(option_write);
    }

    /* Close I2C-0 */
    close_i2c_device();

    return 0;
}


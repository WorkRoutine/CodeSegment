/*
 * Can 2 terminal
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <pthread.h>
#include <transfer.h>
#include <can.h>
#include <command.h>
#include <signals.h>

static void usage(const char *program_name)
{
    printf("%s 1.0(2017-12-13)\n",program_name);
    printf("Transfer message on CAN bus\n");
    printf("Usage:%s -b <Can Bus> [-r/-i/-o <module>]\n", program_name);
    printf("Usage:%s -b <Can Bus> [-l <on/off> -n <node>]\n", program_name);
    printf("Usage:%s -b <Can Bus> [-t <node>]\n", program_name);
    printf(" -b <bus>    --Bus          Can Bus number\n");
    printf(" -n <node>   --node         Node number\n");
    printf(" -h          --help         Help information\n");
    printf(" -t <node>   --trigger      Reset specific node\n");
    printf(" -r <module> --reset        Reset specific module\n");
    printf(" -o <nodule> --poweron      Power on specific module\n");
    printf(" -i <module> --poweroff     Power off specific module\n");
    printf(" -l <on/off> --log <on/off> log on/off for specific module\n");
    printf(" -g <module> --Ethernet     Obtain Ethernet state for specific module\n");
    printf(" -k <module> --Kill         Reset specifical node that doesn't link to Ethernet\n");
    printf(" -S <node>   --Status       Obtain specifical startup state\n");
}

int main(int argc,char *argv[])
{
    char *bus_name    = NULL;
    char *node_name   = NULL;
    char *module_name = NULL;
    /* Option flag:
     * -- bit0: Bus
     * -- bit1: Node
     * -- bit2: Power on node
     * -- bit3: Power off node
     * -- bit4: Reset node
     * -- bit5: Power on module
     * -- bit6: Power off module
     * -- bit7: Reset module
     * -- bit8: Log on
     * -- bit9: Log off
     * -- bit10: help
     * -- bit11: Gethernet Status
     * -- bit12: Kill specifical node on module
     * -- bit13: VPU2600 Startup status
     */
    unsigned long flag = 0;

    const char *short_opts = "hb:n:r:i:o:t:l:g:k:";
    const struct option long_opts[] = {
        {"help", no_argument, NULL, 'h'},
        {"bus", required_argument, NULL, 'b'},
        {"node", required_argument, NULL, 'n'},
        {"log", required_argument, NULL, 'l'},
        {"reset", required_argument, NULL, 'r'},
        {"shutdown", required_argument, NULL, 'i'},
        {"power-on", required_argument, NULL, 'o'},
        {"trigger", required_argument, NULL, 't'},
        {"gethernet", required_argument, NULL, 'g'},
        {"kill", required_argument, NULL, 'k'},
        {"startup", required_argument, NULL, 'S'},
        {0,0,0,0}
    };
    int c, ret;
    opterr = 0;

    while((c = getopt_long(argc, argv, short_opts, long_opts, NULL)) != -1) {
        switch(c) {
            case 'h':
                flag |= 1 << 10;
                break;
            case 'b':
                flag |= 1;
                bus_name = optarg;
                break;
            case 'n':
                flag |= 1 << 1;
                node_name = optarg;
                break;
            case 'l':
                if (strncmp(optarg, "on", 2) == 0)
                    flag |= 1 << 8;
                else if (strncmp(optarg, "off", 3) == 0)
                    flag |= 1 << 9;
                else
                    usage(argv[0]);
                break;
            case 'r': /* Reset specific module */
                module_name = optarg;
                flag |= 1 << 7;
                break;
            case 'i': /* Power off specific module */
                module_name = optarg;
                flag |= 1 << 6;
                break;
            case 'o': /* Power on specific module */
                module_name = optarg;
                flag |= 1 << 5;
                break;
            case 't': /* Reset specific node */
                node_name = optarg;
                flag |= 1 << 4;
                break;
            case 'g':
                module_name = optarg;
                flag |= 1 << 11;
                break;
            case 'k':
                module_name = optarg;
                flag |= 1 << 12;
                break;
            case 'S':
                node_name = optarg;
                flag |= 1 << 13;
                break;
            case '?':
                if(optopt == 'b' || optopt == 'n' || optopt == 't' ||
                   optopt == 'r' || optopt == 'i' || optopt == 'o' ||
                   optopt == 'l' || optopt == 'g' || optopt == 'k' ||
                   optopt == 'S')
                    printf("Error:option -%c requires an argument\n",optopt);
                else if(isprint(optopt))
                    printf("Error:unknow option '-%c'\n", optopt);
                else
                    printf("Error:unknow option character '\\x%x\n'", optopt);
                return 1;
            default:
                abort();
        }
    }
    /* Show help information and Re-check specific argumane */
    if(flag == 1 || (bus_name == NULL)) {
        usage(argv[0]);
        if (bus_name == NULL)
            return -1;
        return 0;
    }
    if (flag & 0x8E0) {
        if (module_name == NULL) {
            usage(argv[0]);
            return -1;
        }
    }
    if (flag & 0x31E) {
        if (node_name == NULL) {
            usage(argv[0]);
            return -1;
        }
    }

    /* Open specifia CAN bus */
    if (can_open(bus_name) < 0) {
        printf("Can't open CAN device: %s\n", bus_name);
        return -1;
    }

    /* Initialize signal machanism on CAN2Ter */
    signal_init();

    /* Prio to deal with command, that reset > power on/off > trigger */
    
    /* Reset specific module */
    if ((flag >> 7) & 0x1) {
        int module_id;

        sscanf(module_name, "%d", &module_id);
        if (reset_module(module_id, &system_can)) {
            printf("Can't reset module %d\n", module_id);
            can_close();
            return -1;
        }
        can_close();
        return 0;
    }

    /* Power on specific module */
    if ((flag >> 5) & 0x1) {
        int module_id;

        sscanf(module_name, "%d", &module_id);
        if (poweron_module(module_id, &system_can)) {
            printf("Can't power on module %d\n", module_id);
            can_close();
            return -1;
        }
    }    

    /* Power off specific module */
    if ((flag >> 6) & 0x1) {
        int module_id;
        
        sscanf(module_name, "%d", &module_id);
        if (poweroff_module(module_id, &system_can)) {
            printf("Can't power off module %d\n", module_id);
            can_close();
            return -1;
        }
        can_close();
        return 0;
    }

    /* Reset specific node */
    if ((flag >> 4) & 0x1) {
        int node_id;

        sscanf(node_name, "%d", &node_id);
        if (reset_node(node_id, &system_can)) {
            printf("Can't reset node %d\n", node_id);
            can_close();
            return -1;
        }
        can_close();
        return 0;
    }

    /* Log on specific node */
    if ((flag >> 8) & 0x1) {
        int node_id;

        sscanf(node_name, "%d", &node_id);
        if (enable_node_log(node_id, &system_can)) {
            printf("Can't enable log for node %d\n", node_id);
            can_close();
            return -1;
        }
        /* Startup log monitor */
        monitor_send_thread();
        monitor_recv_thread();
        monitor_launch();
        can_close();
        return 0;
    }

    /* Log off specific node */
    if ((flag >> 9) & 0x1) {
        int node_id;

        sscanf(node_name, "%d", &node_id);
        if (disable_node_log(node_id, &system_can)) {
            printf("Can't disable log for node %d\n", node_id);
            can_close();
            return -1;
        }
        can_close();
        return 0;
    }

    /* Obtain Ethernet status for specific Module */
    if ((flag >> 11) & 0x1) {
        int mode;
        int status = 0;

        sscanf(module_name, "%d", &mode);
        status = obtain_module_ethernet_status(mode, &system_can);
        if (status < 0) {
            can_close();
            printf("99");
            return -1;
        }
        printf("%d", status); /* Output for scripts */
        can_close();
        return 0;
    }

    /* Kill specifical node on module */
    if ((flag >> 12) & 0x1) {
        int mode;
        int status = 0;
        int i;

        sscanf(module_name, "%d", &mode);
        status = obtain_module_ethernet_status(mode, &system_can);
        if (status < 0) {
            can_close();
            printf("99");
            return -1;
        }
        for (i = 0; i < 6; i++) {
            if (!((status >> i) & 0x1)) {
                /* Reset specifical node */
                if (reset_node(mode * 6 + i, &system_can)) {
                    printf("Can't reset node %d\n", mode * 6 + i);
                    can_close();
                    return -1;
                }
            }
        }
        
        can_close();
        return 0;
    }

    /* Obtain Specific node startup state */
    if ((flag >> 13) & 0x1) {
        int mode;
        int status = 0;

        sscanf(node_name, "%d", &mode);
        status = obtain_node_startup_status(mode, &system_can);
        if (status < 0) {
            can_close();
            printf("99");
            return -1;
        }
        printf("%d", status); /* Output for scripts */
        can_close();
        return 0;
    }
 

    can_close();
    return 0;
}

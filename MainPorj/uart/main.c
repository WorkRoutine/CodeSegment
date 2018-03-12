/*
 * Aup Uart toolchain
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <pthread.h>
#include <uart.h>
#include <signals.h>
#include <command.h>

static void usage(const char *program_name)
{
    printf("%s 1.0(2018-01-19)\n",program_name);
    printf("Transfer message on Uart\n");
    printf("Usage:%s -p <Uart-no> [-r] [-w <message>] [-b <baudrate>]\n", 
            program_name);
    printf(" -p <uart-name>  --Uart          UART Name\n");
    printf(" -b <baudrate>   --Baudrate      UART Baudrate\n");
    printf(" -r              --Read          Read Message\n");
    printf(" -w <mesge>      --Write         Write Message\n");
    printf(" -m              --MAC           Obtain MAC infomation\n");
    printf(" -i <module>     --Close         Power off AUP2600\n");
    printf(" -o <module>     --Open          Power on  AUP2600\n");
    printf(" -k 0            --Kill          Power off MGT2600\n");
    printf(" -k 1            --Kill          Power on MGT2600\n");
    printf(" -k 2            --Kill          Reset MGT2600\n");
    printf(" -E              --Ethernet      VPU2600 Ethernet OK\n");
    printf(" -s              --slot          PowerManage Slot\n");
    printf(" -S              --Switch        VPU2600 Swtich link\n");
}

int main(int argc,char *argv[])
{
    char *uart_name   = NULL;
    char *baudrate_name  = NULL;
    char *message = NULL;
    char *module_name = NULL;
    char *kill_date = NULL;
    char *mcu_info = NULL;

    /*
     * flag layer
     * -- bit0: help 
     * -- bit1: uart name
     * -- bit2: baudrate
     * -- bit3: read
     * -- bit4: write
     * -- bit5: mac address
     * -- bit6: close AUP2600
     * -- bit7: open  AUP2600
     * -- bit8: (Reset)/(Power on)/(Power off) MGT2600
     * -- bit9: VPU2600 Ethernet OK.
     * -- bitA: Power-Manage Slot.
     * -- bitB: AUP2600 Switch Link
     */
    const char *short_opts = "hp:w:b:i:o:k:m:rEsS";
    const struct option long_opts[] = {
        {"help", no_argument, NULL, 'h'},
        {"platform", required_argument, NULL, 'p'},
        {"baudrate", required_argument, NULL, 'b'},
        {"read", no_argument, NULL, 'r'},
        {"MAC", required_argument, NULL, 'm'},
        {"Kill", required_argument, NULL, 'k'},
        {"close", required_argument, NULL, 'i'},
        {"open", required_argument, NULL, 'o'},
        {"write", required_argument, NULL, 'i'},
        {"Ethernet", no_argument, NULL, 'E'},
        {"Slot", no_argument, NULL, 's'},
        {"Switch", no_argument, NULL, 'S'},
        {0,0,0,0}
    };
    int flag = 0;
    int c, ret;
    int uart_node;
    opterr = 0;

    while((c = getopt_long(argc, argv, short_opts, long_opts, NULL)) != -1) {
        switch(c) {
            case 'h':
                flag |= 1;
                break;
            case 'p':
                uart_name = optarg;
                flag |= (1 << 1);
                break;
            case 'b':
                baudrate_name = optarg;
                flag |= (1 << 2);
                break;
            case 'r': /* Read message from UART */
                flag |= (1 << 3);
                break;
            case 'm': /* Obtain MAC from UART */
                mcu_info = optarg;
                flag |= (1 << 5);
                break;
            case 'i': /* Power off AUP2600 */
                module_name = optarg;
                flag |= (1 << 6);
                break;
            case 'o': /* Power on AUP2600 */
                module_name = optarg;
                flag |= (1 << 7);
                break;
            case 'w': /* power off specific module */
                message = optarg;
                flag |= (1 << 4);
                break;
            case 'k':
                flag |= (1 << 8);
                kill_date = optarg;
                break;
            case 'E':
                flag |= (1 << 9);
                break;
            case 's':
                flag |= (1 << 10);
                break;
            case 'S':
                flag |= (1 << 11);
                break;
            case '?':
                if(optopt == 'b' || optopt == 'p' || optopt == 'w' ||
                   optopt == 'i' || optopt == 'o' || optopt == 'k')
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
    /* Show help information */
    if(flag == 1 || (uart_name == NULL)) {
        usage(argv[0]);
        return 0;
    }
    if (!((flag >> 1) & 0x1)) {
        usage(argv[0]);
        return 0;
    }

    if (strncmp(uart_name, "uart0", 5) == 0) {
        uart_node = 0;
    } else if (strncmp(uart_name, "uart1", 5) == 0) {
        uart_node = 1;
    } else if (strncmp(uart_name, "uart2", 5) == 0) {
        uart_node = 2;
    } else {
        usage(argv[0]);
        return -1;
    }
    /* Open specifia CAN bus */
    uart_open(uart_node);

    /* Initialize signal machanism on CAN2Ter */
    signal_init();

    /* Set UART */
    set_opt(0, 0, 'N', 0);

    /* Obtain MAC address */
    if ((flag >> 5) & 0x1) {
        if (!mcu_info) {
            printf("Error: unable to obtain MCU information file\n");
            return 1;
        }
        obtain_MCU_information(mcu_info);
    }

    /* close AUP2600 */
    if ((flag >> 6) & 0x1) {
        int modnum;

        sscanf(module_name, "%d", &modnum);
        power_off_AUP2600(modnum);
    }

    /* Open AUP2600 */
    if ((flag >> 7) & 0x1) {
        int modnum;

        sscanf(module_name, "%d", &modnum);
        power_on_AUP2600(modnum);
    }

    /* Reset MGT2600 */
    if ((flag >> 8) & 0x1) {
        int opt;

        sscanf(kill_date, "%d", &opt);
        reset_MGT2600(opt);
    }

    /* AUP2600 Ethernet OK */
    if ((flag >> 9) & 0x1) {
        if (node_ethernet_ok() == 99) {
            uart_close();
            return 99;
        }
    }

    /* Obtain current valid POWER-Manage Slot number */
    if ((flag >> 10) & 0x1) {
        int slot;

        slot = obtain_PMU_slot();
        if (slot < 0) {
            uart_close();
            return -1;
        }
        printf("%d", slot);
    }
    /* AUP2600 Swtich Link */
    if ((flag >> 11) & 0x1) {
        node_switch_link();    
    }

    uart_close();
    return 0;
}

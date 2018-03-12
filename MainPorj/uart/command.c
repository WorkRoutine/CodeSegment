/*
 * Command for uart
 */
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <command.h>
#include <uart.h>

/* Command Number */
#define MCU_CMD_NR      4
/* Maximum information length */
#define MCU_INFO_MAX    256
/* Handler for parse string */
typedef void (*parse_cmd_common_t)(int fd, char *buffer);

/* header funciton topview  */
void parse_get_network(int fd, char *buffer);
void parse_get_monitor_mac(int fd, char *buffer);
void parse_get_node_index(int fd, char *buffer);

const char *MCU_comand[MCU_CMD_NR] = {
    "##get_network##",
    "##get_monitor_mac##",
    "##get_node_index##",
    NULL,
};

/* Contents length from MCU, Note! the order with MCU_command */
int MCU_contents_len[MCU_CMD_NR] = {
    20,
    20,
    7,
    0,
};

/* Handler array */
parse_cmd_common_t parse_cmd_common[] = {
    parse_get_network,        /* Command: ##get_network## */
    parse_get_monitor_mac,    /* Command: ##get_monitor_mac## */
    parse_get_node_index,         /* Command: ##get_node_index## */
};

/* format MAC address */
static void format_mac_address(char *src, char *desc)
{
    int i, j = 0;

    for (i = 0; i < 12; i++) {
        if ((i % 2 == 0) && (i != 0)) {
            desc[j++] = ':';
        }
        desc[j++] = src[i];
    }
    desc[j] = '\0';
}

/* parse special string to obtain format MAC address information 
 *
 * Scheme information:
 *
 *   Line0: Original information
 *   Line1: Format MAC Address
 *   Line2: Format IP  Address
 *   Line3: Tail IP Address
 */
void parse_get_network(int fd, char *buffer)
{
    int i, j;
    char target[80];

    /* Clearup target buffer */
    memset(target, 0, 80);

    /* Filter special characher */
    for (i = 0, j = 0; i < 20; i++) {
        if (buffer[i] == '@')
            continue;
        if (buffer[i] == '&' && j == 12) {
            target[j] = '\0';
            break;
        }
        target[j++] = buffer[i];
    }
    if (j > 12) {
        perror("Bad MAC address information");
        return -1;
    }
    /* Add new line, Orignal length [12:0] */
    target[12] = '\0';
    /* Obtain Format MAC Address, [30:13] */ 
    format_mac_address(target, &target[13]);
    /* Reserved line2 and line3 */
    target[12] = '\n';
    target[30] = '\n';
    target[31] = '\n';
    target[32] = '\n';
    write(fd, target, 33);
}

/* parse special string to obtain format Manager MAC address information 
 *
 * Scheme information:
 *
 *   Line0: Original information
 *   Line1: Format MAC Address
 *   Line2: Reserved
 *   Line3: Reserved
 */
void parse_get_monitor_mac(int fd, char *buffer)
{
    int i, j;
    char target[80];

    /* Clearup target buffer */
    memset(target, 0, 80);

    /* Filter special characher */
    for (i = 0, j = 0; i < 20; i++) {
        if (buffer[i] == '@')
            continue;
        if (buffer[i] == '&' && j == 12) {
            target[j] = '\0';
            break;
        }
        target[j++] = buffer[i];
    }

    if (j > 12) {
        perror("Bad Manager MAC address information");
        return -1;
    }
    /* Add new line, Orignal length [12:0] */
    target[12] = '\0';
    /* Obtain Format MAC Address, [30:13] */
    format_mac_address(target, &target[13]);
    /* Reserved line2 and line3 */
    target[12] = '\n';
    target[30] = '\n';
    target[31] = '\n';
    target[32] = '\n';
    write(fd, target, 33);
}

/* parse special string to obtain slot and node information 
 *
 * Scheme information:
 *
 *   Line0: Original information
 *   Line1: slot
 *   Line2: node
 *   Line3: Reserved
 */
void parse_get_node_index(int fd, char *buffer)
{
    int i, j;
    char target[80];
    int slot, node;

    /* Clearup target buffer */
    memset(target, 0, 80);

    /* Filter special characher */
    for (i = 0, j = 0; i < 7; i++) {
        if (buffer[i] == '@' || buffer[i] == '#')
            continue;
        if (buffer[i] == '&' && j == 4) {
            target[j] = '\0';
            break;
        }
        target[j++] = buffer[i];
    }

    if (j > 4) {
        perror("Bad slot/node information");
        return -1;
    }
    /* Add new line */
    target[4] = '\n';
    /* obtain Node inforamtion */
    target[40] = target[2];
    target[41] = target[3];
    target[42] = '\0';

    sscanf(&target[40], "%x", &node);
    sprintf(&target[5], "%d", node);
    target[6] = '\n';
    /* otbain Slot information */
    target[40] = target[0];
    target[41] = target[1];
    target[42] = '\0';

    sscanf(&target[40], "%x", &node);
    sprintf(&target[7], "%d", node);
    if (node > 9)
        node = 9;
    else
        node = 8;
    target[node] = '\n';
    /* Reserved line3 */
    write(fd, target, 8);
}

/*
 * Obtain Information from MCU-uart entry
 */
int obtain_MCU_information(char *filename)
{
    int MCU_fd;
    int nread, i;
    char *buffer;

    /* Open MCU information file to store contents. */
    if ((MCU_fd = open(filename, O_RDWR | O_CREAT | O_NONBLOCK)) < 0) {
        perror("Open MCU file failed.");
        return -1;
    }

    buffer = (char *)malloc(MCU_INFO_MAX);
    /* Execute MCU command to obtain special information */
    for (i = 0; i < MCU_CMD_NR - 1; i++) {
        /* clear buffer */
        memset(buffer, 0, MCU_INFO_MAX);
        /* Send command to MCU */
        uart_write(MCU_comand[i]);
        /* Read information from MCU-UART */
        nread = uart_read(&buffer, MCU_contents_len[i]);
        /* Handle original information form MCU-UART */
        parse_cmd_common[i](MCU_fd, buffer);
    }

    free(buffer);
    /* Close MCU information file. */
    close(MCU_fd);
    return 0;
}

/* MGT2600 power on Machine */
int power_on_AUP2600(int mod)
{
    char *buf;
    char *cmd, *ack;

    if (mod == 0) {
        cmd = POWERMODULE0_POWER_ON;
        ack = POWERMODULE0_POWER_ON_ACK;
    } else if (mod == 1) {
        cmd = POWERMODULE1_POWER_ON;
        ack = POWERMODULE1_POWER_ON_ACK;
    }

    buf = malloc(40);
    memset(buf, 0, 40);
    uart_write(cmd);
    uart_read(&buf, strlen(ack));
    if (strncmp(buf, ack, strlen(ack)) == 0) {
        free(buf);
        return 0;
    } else {
        return -1;
    }
}

/* MGT2600 power off Machine */
int power_off_AUP2600(int mod)
{
    char *buf;
    char *cmd, *ack;

    if (mod == 0) {
        cmd = POWERMODULE0_POWER_OFF;
        ack = POWERMODULE0_POWER_OFF_ACK;
    } else if (mod == 1) {
        cmd = POWERMODULE1_POWER_OFF;
        ack = POWERMODULE1_POWER_OFF_ACK;
    }


    buf = malloc(40);
    memset(buf, 0, 40);
    uart_write(cmd);
    uart_read(&buf, strlen(ack));
    if (strncmp(buf, ack, strlen(ack)) == 0) {
        free(buf);
        return 0;
    } else {
        return -1;
    }
}

/* Reset MGT2600 */
void reset_MGT2600(int opt)
{
    if (opt == 0) {
        /* Power off MGT2600 */
        uart_write(MGT2600POWEROFF);
    } else if (opt == 1) {
        /* Power on MGT2600 */
        uart_write(MGT2600POWERON);
    } else if (opt == 2) {
        /* Reset MGT2600 */
        uart_write(MGT2600RESET);
    } else
        return;
}

/* Ethernet ok */
int node_ethernet_ok(void)
{
    char *buf;

    buf = malloc(40);
    memset(buf, 0, 40);
    uart_write(NODE_ETH_LINK);
    uart_read(&buf, strlen(NODE_ETH_LINK_ACK));
    if (strncmp(buf, NODE_ETH_LINK_ACK,
                     strlen(NODE_ETH_LINK_ACK)) == 0) {
        free(buf);
        return 0;
    } else {
        free(buf);
        return 99;
    }
}

/* Switch Port OK */
int node_switch_link(void)
{
    char *buf;
    
    buf = malloc(40);
    memset(buf, 0, 40);
    uart_write(NODE_SWITCH_LINK);
    uart_read(&buf, strlen(NODE_SWITCH_LINK_ACK));
    if (strncmp(buf, NODE_SWITCH_LINK_ACK,
                     strlen(NODE_SWITCH_LINK_ACK)) == 0) {
        free(buf);
        return 0;
    } else {
        free(buf);
        return -1;
    }
}

/* Obtain Current valid PMU */
int obtain_PMU_slot(void)
{
    char *buf;

    buf = malloc(40);
    memset(buf, 0, 40);
    /* Check Slot 0 */
    uart_write(OBTAIN_POWERMANAGE0);
    uart_read(&buf, strlen(POWERMANAGE0STATUSNO));
    if (strncmp(buf, POWERMANAGE0STATUSOK, 
                        strlen(POWERMANAGE0STATUSOK)) == 0) {
        /* Power Module Slot has plugged */
        free(buf);
        return 0;
    } else {
        free(buf);
        return 1;
    }
}

/*
 * parse command from command line
 * (C) 2018.03 <buddy.zhang@aliyun.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <command.h>

/* Mulitp argument list */
char *aup_argument_list[6];

static struct aup_cmd_struct *parse_aup_cmd(const char *string)
{
    int i;

    for (i = 0; aup_cmd_list[i].cmdline; i++) {
        if (strcmp(string, aup_cmd_list[i].cmdline) == 0) {
            /* Obtain special command structure */
            return &aup_cmd_list[i];
        }
    }
    printf("Invalid command line: %s\n", string);
    return NULL;
}

/* Read operation */
int read_common_entry(const char *string)
{
    struct aup_cmd_struct *cmd;

    cmd = parse_aup_cmd(string);

    /* Execute read operation */
    cmd->read(cmd);
    return 0;
}

/* Write operation */
int write_common_entry(const char *string)
{
    struct aup_cmd_struct *cmd;

    cmd = parse_aup_cmd(string);

    /* Execute write operation */
    cmd->write(cmd);
    return 0;
}

/* 
 * parse mac address from command line
 *
 * output format MAC address.
 */
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
            sscanf(aup_argument_list[i], "%x", (unsigned int *)(unsigned long)(((unsigned char *)mac + i)));
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

        strncpy(buf, (const char *)(unsigned long)((char *)aup_argument_list[0] + pos[i]), length);
        buf[length] = '\0';

        sscanf(buf, "%x", (unsigned int *)(unsigned long)(((unsigned char *)mac + i)));
    }
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

/* parse ip address */
void parse_ip_address(unsigned char *ip)
{
    int i, j;
    int pos[8];
    int value;

    if (!aup_argument_list[0]) {
        printf("ERROR: empty mac address.\n");
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

/* dump format boolean */
void dump_boolean(unsigned char value, int max)
{
    if (value)
        printf("1");
    else
        printf("0");
}

void dump_nbyte(unsigned char *buf, int len, int reversal)
{

}

/* dump format password */
void dump_password(unsigned char *buf)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (((buf[i] >= 'a') && (buf[i] <= 'z')) ||
            ((buf[i] >= 'A') && (buf[i] <= 'Z')) ||
            ((buf[i] >= '0') && (buf[i] <= '9'))) {
            /* Nothing */;
        } else {
            if (buf[i] == '&')
                break;
            exit (1);
        }
    }

    /* Parse password */
    for (i = 0; i < 8; i++) {
        if (buf[i] != '&')
            printf("%c", buf[i]);
        else
            i = 20;
    }
}

void parse_web_passwd(unsigned char *pwd)
{
    char *str = aup_argument_list[0];
    int pos[8];
    int i;

    if (!aup_argument_list[0]) {
        printf("ERROR: empty password.\n");
        exit (1);
    }

    if (strlen(aup_argument_list[0]) > 8) {
        printf("ERROR: Password too long! Correct size is less then 9.\n");
        exit (1);
    }
    /* Diagnose upper and lower, number on password */
    for (i = 0; i < strlen(str); i++) {
        if ((str[i] >= '0' && str[i] <= '9') ||
            (str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= 'A' && str[i] <= 'Z')) {
            pwd[i] = str[i];
        } else {
            printf("ERROR: Password need [0-9] or [a-z] or [A-Z]\n");
            exit (1);
        }
    }
    if (i < 8)
        pwd[i] = '&';
}

void dump_port(unsigned char *buf)
{
    int port;

    if (buf[0] == 0x00) {
        printf("%d", buf[1]);
    } else {
        port = buf[0] * 256 + buf[1];
        printf("%d", port);
    }
}

void parse_port(unsigned char *buf)
{
    int port;

    /* parse with dhcp from command line */
    sscanf(aup_argument_list[0], "%d", &port);
    if (port <= 0 || port > 65535) {
        printf("Invalid port number for Zabbix server port\n");
        exit(1);
    } else if (port < 256) {
        buf[0] = 0;
        buf[1] = (unsigned char)(unsigned long)port;
    } else if (port >= 256) {
        buf[1] = (unsigned char)(unsigned long)(port & 0xFF);
        buf[0] = (unsigned char)(unsigned long)((port >> 8) & 0xff);
    } else {
        printf("Invalid port number for Zabbix server port\n");
        exit(1);
    }
}

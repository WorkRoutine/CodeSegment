/*
 * Command line
 * (C) 2018.03 <buddy.zhang@aliyun.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <command.h>
#include <i2c.h>

/* Top command */
const struct aup_cmd_struct aup_cmd_list[] = {
    {
        .eeprom_addr = 0x00,
        .len         = 6,
        .cmdline     = "internal_mac",
        .usage       = "%s -r/-w intermal_mac",
        .desc        = "Read/Write internal management MAC(0x00-0x05)",
        .read        = aup_MAC_read,
        .write       = aup_MAC_write,
    },
    {
        .eeprom_addr = 0x06,
        .len         = 4,
        .cmdline     = "internal_ip",
        .usage       = "%s -r/-w intermal_ip",
        .desc        = "Read/Write internal management IP(0x06-0x09)",
        .read        = aup_IP_read,
        .write       = aup_IP_write,
    },
    {
        .eeprom_addr = 0x0a,
        .len         = 4,
        .cmdline     = "internal_netmask",
        .usage       = "%s -r/-w intermal_netmask",
        .desc        = "Read/Write internal management netmask(0x0a-0x0d)",
        .read        = aup_IP_read,
        .write       = aup_IP_write,
    },
    {
        .eeprom_addr = 0x0e,
        .len         = 4,
        .cmdline     = "internal_gateway",
        .usage       = "%s -r/-w intermal_gateway",
        .desc        = "Read/Write internal management gateway(0x0e-0x11)",
        .read        = aup_IP_read,
        .write       = aup_IP_write,
    },
    {
        .eeprom_addr = 0x12,
        .len         = 4,
        .cmdline     = "internal_dns",
        .usage       = "%s -r/-w intermal_dns",
        .desc        = "Read/Write internal management dns(0x12-0x15)",
        .read        = aup_IP_read,
        .write       = aup_IP_write,
    },
    {
        .eeprom_addr = 0x16,
        .len         = 4,
        .cmdline     = "internal_dns1",
        .usage       = "%s -r/-w intermal_dns1",
        .desc        = "Read/Write internal management dns1(0x16-0x19)",
        .read        = aup_IP_read,
        .write       = aup_IP_write,
    },
    {
        .eeprom_addr = 0x1a,
        .len         = 1,
        .cmdline     = "internal_use_dhcp",
        .usage       = "%s -r/-w intermal_use_dhcp",
        .desc        = "Read/Write internal management use dhcp(0x1a)",
        .read        = aup_boolean_read,
        .write       = aup_boolean_write,
    },
    {
        .eeprom_addr = 0x1b,
        .len         = 1,
        .cmdline     = "external_use_gateway",
        .usage       = "%s -r/-w external_use_gateway",
        .desc        = "Read/Write external management use gateway(0x1b) 0 unset yet",
        .read        = aup_boolean_read,
        .write       = aup_boolean_write,
    },
    {
        .eeprom_addr = 0x1c,
        .len         = 1,
        .cmdline     = "external_use_dns",
        .usage       = "%s -r/-w external_use_dns",
        .desc        = "Read/Write external management use dns(0x1c) o unset yet",
        .read        = aup_boolean_read,
        .write       = aup_boolean_write,
    },
    {
        .eeprom_addr = 0x1d,
        .len         = 1,
        .cmdline     = "start_app_device",
        .usage       = "%s -r/-w start_app_device",
        .desc        = "Read/Write start app device information: 0 nandd, 1 nande(0x1D)",
        .read        = aup_boolean_read,
        .write       = aup_boolean_write,
    },
    {
        .eeprom_addr = 0x1e,
        .len         = 1,
        .cmdline     = "have_ntp_serverip",
        .usage       = "%s -r/-w have_ntp_serverip",
        .desc        = "Read/Write start app device information: 0 nandd, 1 nande(0x1E)",
        .read        = aup_boolean_read,
        .write       = aup_boolean_write,
    },
    {
        .eeprom_addr = 0x20,
        .len         = 4,
        .cmdline     = "ntp1_server_ip",
        .usage       = "%s -r/-w ntp1_server_ip",
        .desc        = "Read/Write ntp1 server ip (0x20-0x23)",
        .read        = aup_IP_read,
        .write       = aup_IP_write,
    },
    {
        .eeprom_addr = 0x24,
        .len         = 4,
        .cmdline     = "ntp2_server_ip",
        .usage       = "%s -r/-w ntp2_server_ip",
        .desc        = "Read/Write ntp2 server ip(0x24-0x27)",
        .read        = aup_IP_read,
        .write       = aup_IP_write,
    },
    {
        .eeprom_addr = 0x28,
        .len         = 8,
        .cmdline     = "web_passwd",
        .usage       = "%s -r/-w web_passwd",
        .desc        = "Read/Write management web login password (only allow 0-9/a-z/A-Z)(0x28-0x2F)",
        .read        = aup_passwd_read,
        .write       = aup_passwd_write,
    },
    {
        .eeprom_addr = 0x30,
        .len         = 4,
        .cmdline     = "zabbix_server_ip",
        .usage       = "%s -r/-w zabbix_server_ip",
        .desc        = "Read/Write Zabbix server IP(0x30-0x33)",
        .read        = aup_IP_read,
        .write       = aup_IP_write,
    },
    {
        .eeprom_addr = 0x34,
        .len         = 2,
        .cmdline     = "zabbix_server_port",
        .usage       = "%s -r/-w zabbix_server_port",
        .desc        = "Read/Write Zabbix server port(0x34-0x35)",
        .read        = aup_port_read,
        .write       = aup_port_write,
    },
    {
        .eeprom_addr = 0x36,
        .len         = 4,
        .cmdline     = "syslog_server_ip",
        .usage       = "%s -r/-w syslog_server_ip",
        .desc        = "Read/Write Syslog server IP(0x36-0x39)",
        .read        = aup_IP_read,
        .write       = aup_IP_write,
    },
    {
        .eeprom_addr = 0x3a,
        .len         = 2,
        .cmdline     = "syslog_server_port",
        .usage       = "%s -r/-w syslog_server_port",
        .desc        = "Read/Write Syslog server Port(0x3a-0x3b)",
        .read        = aup_port_read,
        .write       = aup_port_write,
    },
    {
        .eeprom_addr = 0x40,
        .len         = 6,
        .cmdline     = "external_mac",
        .usage       = "%s -r/-w external_mac",
        .desc        = "Read/Write External management MAC address(0x40-0x45)",
        .read        = aup_MAC_read,
        .write       = aup_MAC_write,
    },
    {
        .eeprom_addr = 0x46,
        .len         = 4,
        .cmdline     = "external_ip",
        .usage       = "%s -r/-w external_ip",
        .desc        = "Read/Write External management IP address(0x46-0x49)",
        .read        = aup_IP_read,
        .write       = aup_IP_write,
    },
    {
        .eeprom_addr = 0x4a,
        .len         = 4,
        .cmdline     = "external_netmask",
        .usage       = "%s -r/-w external_netmask",
        .desc        = "Read/Write External management netmask address(0x4a-0x4d)",
        .read        = aup_IP_read,
        .write       = aup_IP_write,
    },
    {
        .eeprom_addr = 0x4e,
        .len         = 4,
        .cmdline     = "external_gateway",
        .usage       = "%s -r/-w external_gateway",
        .desc        = "Read/Write External management gateway address(0x4e-0x51)",
        .read        = aup_IP_read,
        .write       = aup_IP_write,
    },
    {
        .eeprom_addr = 0x52,
        .len         = 4,
        .cmdline     = "external_dns",
        .usage       = "%s -r/-w external_dns",
        .desc        = "Read/Write External management dns address(0x52-0x55)",
        .read        = aup_IP_read,
        .write       = aup_IP_write,
    },
    {
        .eeprom_addr = 0x56,
        .len         = 1,
        .cmdline     = "external_use_dhcp",
        .usage       = "%s -r/-w external_use_dhcp",
        .desc        = "Read/Write External management use dhcp (0x56)",
        .read        = aup_boolean_read,
        .write       = aup_boolean_write,
    },
    {
        .eeprom_addr = 0x57,
        .len         = 1,
        .cmdline     = "default_gateway",
        .usage       = "%s -r/-w default_gateway",
        .desc        = "Read/Write default gateway: 0 internal RGMII, 1 external/panel usb (0x57)",
        .read        = aup_boolean_read,
        .write       = aup_boolean_write,
    },
    {
        .eeprom_addr = 0x58,
        .len         = 4,
        .cmdline     = "force_route_ip1",
        .usage       = "%s -r/-w force_route_ip1",
        .desc        = "Read/Write force route ip 1 (0x58-0x5b)",
        .read        = aup_IP_read,
        .write       = aup_IP_write,
    },
    {
        .eeprom_addr = 0x5c,
        .len         = 4,
        .cmdline     = "force_route_netmask1",
        .usage       = "%s -r/-w force_route_netmask1",
        .desc        = "Read/Write force route netmask 1 (0x5c-0x5f)",
        .read        = aup_IP_read,
        .write       = aup_IP_write,
    },
    {
        .eeprom_addr = 0x60,
        .len         = 4,
        .cmdline     = "force_route_ip2",
        .usage       = "%s -r/-w force_route_ip2",
        .desc        = "Read/Write force route ip 2 (0x60-0x63)",
        .read        = aup_IP_read,
        .write       = aup_IP_write,
    },
    {
        .eeprom_addr = 0x64,
        .len         = 4,
        .cmdline     = "force_route_netmask2",
        .usage       = "%s -r/-w force_route_netmask2",
        .desc        = "Read/Write force route netmask 2 (0x64-0x67)",
        .read        = aup_IP_read,
        .write       = aup_IP_write,
    },
    {
        .eeprom_addr = 0x68,
        .len         = 4,
        .cmdline     = "force_route_ip3",
        .usage       = "%s -r/-w force_route_ip3",
        .desc        = "Read/Write force route ip 3 (0x68-0x6b)",
        .read        = aup_IP_read,
        .write       = aup_IP_write,
    },
    {
        .eeprom_addr = 0x6c,
        .len         = 4,
        .cmdline     = "force_route_netmask3",
        .usage       = "%s -r/-w force_route_netmask3",
        .desc        = "Read/Write force route netmask 3 (0x6c-0x6f)",
        .read        = aup_IP_read,
        .write       = aup_IP_write,
    },
    {
        .eeprom_addr = 0x70,
        .len         = 4,
        .cmdline     = "force_route_ip4",
        .usage       = "%s -r/-w force_route_ip4",
        .desc        = "Read/Write force route ip 4 (0x70-0x73)",
        .read        = aup_IP_read,
        .write       = aup_IP_write,
    },
    {
        .eeprom_addr = 0x74,
        .len         = 4,
        .cmdline     = "force_route_netmask4",
        .usage       = "%s -r/-w force_route_netmask4",
        .desc        = "Read/Write force route netmask 4 (0x74-0x77)",
        .read        = aup_IP_read,
        .write       = aup_IP_write,
    },
    {
        .cmdline = NULL,
    },
};

static int aup_MAC_read(struct aup_cmd_struct *cmd)
{
    unsigned char buf[6];

    /* read mac address from eeprom */
    aup_read_common(i2c_fd, i2c_slave_addr,
                    cmd->eeprom_addr, buf, cmd->len);

    /* format print mac string */
    dump_mac_address(buf, cmd->len, 1);
    return 0;
}

static int aup_MAC_write(struct aup_cmd_struct *cmd)
{
    unsigned char buf[80];

    /* parse mac from command line */
    parse_mac_address(buf);

    /* write mac into eeprom */
    aup_write_common(i2c_fd, i2c_slave_addr,
                     cmd->eeprom_addr, buf, cmd->len);
    return 0;
}

static int aup_IP_read(struct aup_cmd_struct *cmd)
{
    unsigned char buf[4];

    /* read ip address from eeprom */
    aup_read_common(i2c_fd, i2c_slave_addr,
                    cmd->eeprom_addr, buf, cmd->len);

    /* format print ip string */
    dump_ip_address(buf, cmd->len, 1);
    return 0;
}

static int aup_IP_write(struct aup_cmd_struct *cmd)
{
    unsigned char buf[8];

    /* parse ip from command line */
    parse_ip_address(buf);

    /* write ip into eeprom */
    aup_write_common(i2c_fd, i2c_slave_addr,
                     cmd->eeprom_addr, buf, cmd->len);

    return 0;
}

static int aup_boolean_read(struct aup_cmd_struct *cmd)
{
    unsigned char buf;

    /* read dhcp boolean from eeprom */
    aup_read_common(i2c_fd, i2c_slave_addr,
                    cmd->eeprom_addr, &buf, cmd->len);

    /* dump boolean value */
    dump_boolean(buf, 1);
    return 0;
}

static int aup_boolean_write(struct aup_cmd_struct *cmd)
{
    unsigned char buf[16];

    /* parse with dhcp from command line */
    sscanf(aup_argument_list[0], "%d", (unsigned int *)(unsigned long)&buf[0]);

    /* write with dhcp into eeprom */
    aup_write_common(i2c_fd, i2c_slave_addr,
                     cmd->eeprom_addr, buf, cmd->len);
    return 0;
}


static int aup_nbytes_read(struct aup_cmd_struct *cmd)
{
    unsigned char buf;

    /* read dhcp boolean from eeprom */
    aup_read_common(i2c_fd, i2c_slave_addr,
                    cmd->eeprom_addr, &buf, cmd->len);

    /* dump boolean value */
    dump_nbyte(buf, cmd->len, 1);
    return 0;
}

static int aup_nbytes_write(struct aup_cmd_struct *cmd)
{
    unsigned char buf[16];

    /* parse with dhcp from command line */
    sscanf(aup_argument_list[0], "%d", (unsigned int *)(unsigned long)&buf[0]);

    /* write with dhcp into eeprom */
    aup_write_common(i2c_fd, i2c_slave_addr,
                     cmd->eeprom_addr, buf, cmd->len);
    return 0;
}

static int aup_passwd_read(struct aup_cmd_struct *cmd)
{
    unsigned char buf[10];

    /* read dns2 from eeprom */
    aup_read_common(i2c_fd, i2c_slave_addr,
                    cmd->eeprom_addr, buf, cmd->len);

    /* Dump password */
    dump_password(buf);
    return 0;
}

static int aup_passwd_write(struct aup_cmd_struct *cmd)
{
    unsigned char buf[8];

    memset(buf, 0, 8);
    /* Parse web password from user-command */
    parse_web_passwd(buf);

    /* Write web password into eeprom */
    aup_write_common(i2c_fd, i2c_slave_addr,
           cmd->eeprom_addr, buf, cmd->len);
    return 0;
}

static int aup_port_read(struct aup_cmd_struct *cmd)
{
    unsigned char buf[20];

    /* read start device from eeprom */
    aup_read_common(i2c_fd, i2c_slave_addr,
                    cmd->eeprom_addr, &buf, cmd->len);

    dump_port(buf);
    return 0;
}

static int aup_port_write(struct aup_cmd_struct *cmd)
{
    unsigned char buf[16];

    parse_port(buf);

    /* write zabixx server port to EEPROM */
    aup_write_common(i2c_fd, i2c_slave_addr,
                     cmd->eeprom_addr, buf, cmd->len);
    return 0;
}

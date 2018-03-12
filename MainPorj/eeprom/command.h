#ifndef _AUP_COMMAND_H
#define _AUP_COMMAND_H

/* Command handler */
typedef int (*do_func_t)(struct aup_cmd_struct *);

/* Commd structure */
struct aup_cmd_struct
{
    unsigned char eeprom_addr;
    unsigned char len;
    const char *cmdline;
    const char *usage;
    const char *desc;
    do_func_t read;
    do_func_t write;
};

extern const struct aup_cmd_struct aup_cmd_list[];
extern char *aup_argument_list[6];
extern int read_common_entry(const char *string);
extern int write_common_entry(const char *string);
extern void parse_mac_address(unsigned char *mac);
extern void dump_mac_address(unsigned char *buf, int len, int reversal);
extern void dump_ip_address(unsigned char *buf, int len, int reversal);
extern void parse_ip_address(unsigned char *ip);
extern void dump_boolean(unsigned char value, int max);
extern void dump_nbyte(unsigned char *buf, int len, int reversal);
extern void dump_password(unsigned char *buf);
extern void parse_web_passwd(unsigned char *pwd);
extern void dump_port(unsigned char *buf);
extern void parse_port(unsigned char *buf);

static int aup_MAC_read(struct aup_cmd_struct *);
static int aup_MAC_write(struct aup_cmd_struct *);
static int aup_IP_read(struct aup_cmd_struct *);
static int aup_IP_write(struct aup_cmd_struct *);
static int aup_boolean_read(struct aup_cmd_struct *);
static int aup_boolean_write(struct aup_cmd_struct *);
static int aup_passwd_read(struct aup_cmd_struct *cmd);
static int aup_passwd_write(struct aup_cmd_struct *cmd);
static int aup_port_read(struct aup_cmd_struct *cmd);
static int aup_port_write(struct aup_cmd_struct *cmd);

#endif

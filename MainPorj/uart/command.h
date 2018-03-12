#ifndef _COMMAND_H
#define _COMMAND_H

#define POWERMODULE0_POWER_ON        "###POWERMODULE0POWERON###"
#define POWERMODULE0_POWER_ON_ACK    "###POWERMODULE0POWERONACK###"
#define POWERMODULE0_POWER_OFF       "###POWERMODULE0POWEROFF###"
#define POWERMODULE0_POWER_OFF_ACK   "###POWERMODULE0POWEROFFACK###"
#define POWERMODULE1_POWER_ON        "###POWERMODULE1POWERON###"
#define POWERMODULE1_POWER_ON_ACK    "###POWERMODULE1POWERONACK###"
#define POWERMODULE1_POWER_OFF       "###POWERMODULE1POWEROFF###"
#define POWERMODULE1_POWER_OFF_ACK   "###POWERMODULE1POWEROFFACK###"
#define MGT2600RESET                 "###MANAGEMODULERESET###"
#define MGT2600POWERON               "###MANAGEMODULEPOWERON###"
#define MGT2600POWEROFF              "###MANAGEMODULEPOWEROFF###"
#define NODE_ETH_LINK                "##set_node_link##"
#define NODE_SWITCH_LINK             "##set_switch_link##"
#define NODE_ETH_LINK_ACK            "##set_node_link_ack##"
#define NODE_SWITCH_LINK_ACK         "##set_switch_link_ack##"
#define OBTAIN_POWERMANAGE0          "###POWERMODULE0GETSTATUS###"
#define OBTAIN_POWERMANAGE1          "###POWERMODULE1GETSTATUS###"
#define POWERMANAGE0STATUSNO         "###POWERMODULE0GETSTATUSACK###0###"
#define POWERMANAGE0STATUSOK         "###POWERMODULE0GETSTATUSACK###1###"
#define POWERMANAGE1STATUSNO         "###POWERMODULE1GETSTATUSACK###0###"
#define POWERMANAGE1STATUSOK         "###POWERMODULE1GETSTATUSACK###1###"

extern int power_on_AUP2600(int mode);
extern int power_off_AUP2600(int mod);
extern int obtain_mac_addr(void);
extern void reset_MGT2600(int);
extern int node_ethernet_ok(void);
extern int obtain_PMU_slot(void);
extern int node_switch_link(void);
extern int obtain_MCU_information(char *filename);

#endif

#ifndef _CAN_H
#define _CAN_H

#include <net/if.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>

#define MAX_CAN       16

#define CAN_NODE_CMD_BASE      0x300
#define CAN_NODE_DAT_BASE      0x580
#define CAN_MODL_CMD_BASE      0x100
#define CAN_MODL_DAT_BASE      0x100

#define CAN_NODE_WRITE         0x00
#define CAN_NODE_READ          0x01
#define CAN_MODL_WRITE         0x10
#define CAN_MODL_READ          0x11

#define CAN_NODE_POWER         0x4
#define CAN_MODL_POWER         0x8
#define CAN_NODE_LOG           0x10

enum {
    CAN_NODE_POWER_ON,
    CAN_NODE_POWER_OFF,
    CAN_NODE_POWER_STATE,
    CAN_NODE_LOG_ON,
    CAN_NODE_LOG_OFF,
    CAN_NODE_SEND_LOG,
    CAN_NODE_RECV_LOG,
    CAN_MODL_POWER_ON,
    CAN_MODL_POWER_OFF,
    CAN_MODL_ETHERNET_STATUS,
    CAN_CMD_TOTAL
};
/*
 * Define command map: (Master: MGT2600, Node: VPU2600)
 * 1) CAN frame type: (flag [1:0])
 *    00: Data CAN frame    (Write: Master to Node)
 *    01: Data CAN frame    (Read : Node to Master)
 *    10: Command CAN frame (Write: Master to Node)
 *    11: Command CAN frame (Read : Node to Master)
 */
struct aup_can_frame
{
    unsigned int cmd_id;
    unsigned int dat_id;
    unsigned int node;
    unsigned int cmd;
    struct can_frame cx, dx;
};

extern int can_open(char *device);
extern void can_close(void);
extern int CAN_send_messageC(char *buffer, struct aup_can_frame *frame);
extern int CAN_send_messageD(char *buffer, struct aup_can_frame *frame);
extern void enable_CAN_monitor(int cmdid);
extern void disable_CAN_monitor(void);
extern struct aup_can_frame system_can;
extern int can_fd;
#endif

/*
 * Command for CAN2Ter
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <can.h>
#include <signal.h>
#include <sys/time.h>

/*
 * Poweron specific node by CAN-Bus 
 *   While send this command, a specific CAN frame will send to MCU.
 *   And then, MCU will power on specific node.
 *
 *   VPU2600 not support power on one node!
 *   @return: 0 is success
 **/
int poweron_node(int node, struct aup_can_frame *frame)
{
    frame->node   = node;
    frame->cmd_id = CAN_NODE_CMD_BASE + node * 2;
    frame->cmd    = CAN_NODE_POWER_ON;
    /* Tx CAN frame */
    frame->cx.can_id  = frame->cmd_id + 1;
    frame->cx.can_dlc = 3;
    frame->cx.data[0] = 0x13;
    frame->cx.data[1] = frame->node;
    frame->cx.data[2] = 0x1; 
    /* Send message */
    return CAN_send_messageC("Power on Node", frame);
}

/*
 * Poweroff specific node by CAN-Bus
 *   While send this command, a specific CAN frame will send to MCU.
 *   And then, MCU will power off the specific node.
 *
 *   VPU2600 not support power off one node!
 */
int poweroff_node(int node, struct aup_can_frame *frame)
{
    frame->node   = node;
    frame->cmd_id = CAN_NODE_CMD_BASE + node * 2;
    frame->cmd    = CAN_NODE_POWER_ON;
    /* Tx CAN frame */
    frame->cx.can_id  = frame->cmd_id + 1;
    frame->cx.can_dlc = 3;
    frame->cx.data[0] = 0x13;
    frame->cx.data[1] = frame->node;
    frame->cx.data[2] = 0x0;  
    /* Send message */
    return CAN_send_messageC("Power off Node", frame);
}

/*
 * Reset specific node by CAN-Bus
 *   While send this command, a serial of specific CAN frames will send 
 *   to MCU. And then, MCU will reset the specific node.
 *
 *   VPU2600 not support reset one node!
 */
int reset_node(int node, struct aup_can_frame *frame)
{
    /* Power of node */
    if (poweroff_node(node, frame)) {
        printf("Failed to power off node %d\n", node);
        return -1;
    }
    /* Power on node */
    if (poweron_node(node, frame)) {
        printf("Failed to power on node %d\n", node);
        return -1;
    }
    return 0;
}

/*
 * Obtain power status of specific node by CAN-Bus
 *   While send this command, a spcific CAN frame will send to MCU.
 *   And then, procedure will obtain power state of specific node.
 *
 *   @return: 1 is power on
 *            0 is power off
 */
int obtain_node_power(int node, struct aup_can_frame *frame)
{
    frame->node   = node;
    frame->cmd_id = CAN_NODE_CMD_BASE + node * 2;
    frame->cmd    = CAN_NODE_POWER_ON;
    /* Tx CAN frame */
    frame->cx.can_id  = frame->cmd_id + 1;
    frame->cx.can_dlc = 3;
    frame->cx.data[0] = 0x13;
    frame->cx.data[1] = frame->node;
    frame->cx.data[2] = 0x0;
    /* Send message */
    return CAN_send_messageC("Power off Node", frame);
}

/*
 * Power on specific module by CAN-Bus
 *   While send this command, a specific CAN frame will send to MCU.
 *   And then, MCU will power on speicific module
 *
 *   VPU2600 supports this feacture 
 */
int poweron_module(int mod, struct aup_can_frame *frame)
{
    frame->node   = mod;
    frame->cmd_id = CAN_MODL_CMD_BASE + mod * 2;
    frame->cmd    = CAN_MODL_POWER_ON;
    /* Tx CAN frame */
    frame->cx.can_id  = frame->cmd_id + 1;
    frame->cx.can_dlc = 2;
    frame->cx.data[0] = 0x02;
    frame->cx.data[1] = 0x1;
    /* Send message */
    return CAN_send_messageC("Power on Module", frame);
}


/* 
 * Power off specific module by CAN-Bus 
 *   While send this command, a specific CAN frame will send to MCU.
 *   And then, MCU will power off specific module 
 *
 *   VPU2600 supports this feature.
 */
int poweroff_module(int mod, struct aup_can_frame *frame)
{
    frame->node   = mod;
    frame->cmd_id = CAN_MODL_CMD_BASE + mod * 2;
    frame->cmd    = CAN_MODL_POWER_OFF;
    /* Tx CAN frame */
    frame->cx.can_id  = frame->cmd_id + 1;
    frame->cx.can_dlc = 2;
    frame->cx.data[0] = 0x02;
    frame->cx.data[1] = 0x0;
    /* Send message */
    return CAN_send_messageC("Power off Module", frame);
}

/* 
 * Reset specific module by CAN-Bus
 *   While sending this command, a serial of CAN frames will send to MCU.
 *   And then, MCU will reset specific modules.
 *
 *   VPU2600 supports this feature.
 */
int reset_module(int mod, struct aup_can_frame *frame)
{
    /* Power off specific module */
    if (poweroff_module(mod, frame)) {
        printf("Failed to power off moduler %d\n", mod);
        return -1;
    }
    sleep(1);
    /* power on specific module */
    if (poweron_module(mod, frame)) {
        printf("Failed to power on moduler %d\n", mod);
        return -1;
    }
    return 0;
}

/*
 * Enable log for specific node
 *   While sending this command, a CAN frame will send to MCU.
 *   And then, the Uart0 of specific node will point to CAN bus.
 *
 *   VPU2600 support this feature.
 */
int enable_node_log(int node, struct aup_can_frame *frame)
{
    frame->node   = node;
    frame->cmd_id = CAN_NODE_CMD_BASE + node * 2;
    frame->cmd    = CAN_NODE_LOG_ON;
    frame->dat_id = CAN_NODE_DAT_BASE + node * 2;
    /* Tx CAN frame */
    frame->cx.can_id  = frame->cmd_id + 1;
    frame->cx.can_dlc = 3;
    frame->cx.data[0] = 0x15;
    frame->cx.data[1] = frame->node;
    frame->cx.data[2] = 0x1;

    /* Mointer specific CAN fraome */
    enable_CAN_monitor(frame->dat_id);
    /* Send message */
    return CAN_send_messageC("Power off Module", frame);
}

/*
 * Disable log for specific node
 *   While sending this command, a CAN frame will send to MCU.
 *   And then, the Uart0 of specific node will not send to CAN bus.
 *
 *   VPU2600 support this feature.
 */
int disable_node_log(int node, struct aup_can_frame *frame)
{
    frame->node   = node;
    frame->cmd_id = CAN_NODE_CMD_BASE + node * 2;
    frame->cmd    = CAN_NODE_LOG_OFF;
    /* Tx CAN frame */
    frame->cx.can_id  = frame->cmd_id + 1;
    frame->cx.can_dlc = 3;
    frame->cx.data[0] = 0x15;
    frame->cx.data[1] = frame->node;
    frame->cx.data[2] = 0x0;

    /* Cansol CAN monitor */
    disable_CAN_monitor();
    /* Send message */
    return CAN_send_messageC("Power off Module", frame);
}

/*
 * Obtain specific module ethernet  status.
 */
int obtain_module_ethernet_status(int mod, struct aup_can_frame *frame)
{
    int bytes;
    struct can_frame rx_frame;

    frame->node   = mod;
    frame->cmd_id = CAN_MODL_CMD_BASE + mod * 2;
    frame->cmd    = CAN_MODL_ETHERNET_STATUS;
    frame->dat_id = CAN_MODL_CMD_BASE + mod * 2;
    /* Tx CAN frame */
    frame->cx.can_id  = frame->cmd_id + 1;
    frame->cx.can_dlc = 1;
    frame->cx.data[0] = 0x09;
    /* Moniter specific CAN frame */
    enable_CAN_monitor(frame->dat_id);
    /* Send message */
    CAN_send_messageC("Request Module Ethernet Status", frame);
    usleep(100000);
    /* Read CAN frame from CAN Bus */
    bytes = read(can_fd, &rx_frame, sizeof(rx_frame));
    if (bytes > 0) {
        if (rx_frame.data[0] == 0x9)
            return rx_frame.data[1];
    }
    return -1;
}

/*
 * Obtain specific module ethernet  status.
 */
int obtain_node_startup_status(int mod, struct aup_can_frame *frame)
{
    int bytes;
    struct can_frame rx_frame;

    frame->node   = mod;
    frame->cmd_id = CAN_MODL_CMD_BASE + mod * 2;
    frame->cmd    = CAN_MODL_ETHERNET_STATUS;
    frame->dat_id = CAN_MODL_CMD_BASE + mod * 2;
    /* Tx CAN frame */
    frame->cx.can_id  = frame->cmd_id + 1;
    frame->cx.can_dlc = 1;
    frame->cx.data[0] = 0x09;
    /* Moniter specific CAN frame */
    enable_CAN_monitor(frame->dat_id);
    /* Send message */
    CAN_send_messageC("Request Module Ethernet Status", frame);
    usleep(100000);
    /* Read CAN frame from CAN Bus */
    bytes = read(can_fd, &rx_frame, sizeof(rx_frame));
    if (bytes > 0) {
        if (rx_frame.data[0] == 0x9)
            return rx_frame.data[1];
    }
    return -1;
}

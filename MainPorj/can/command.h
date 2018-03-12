#ifndef _COMMAND_H
#define _COMMAND_H

extern int poweron_node(int node, struct aup_can_frame *frame);
extern int poweroff_node(int node, struct aup_can_frame *frame);
extern int reset_node(int node, struct aup_can_frame *frame);
extern int obtain_node_power(int node, struct aup_can_frame *frame);
extern int poweron_module(int mod, struct aup_can_frame *frame);
extern int poweroff_module(int mod, struct aup_can_frame *frame);
extern int reset_module(int mod, struct aup_can_frame *frame);
extern int enable_node_log(int node, struct aup_can_frame *frame);
extern int disable_node_log(int node, struct aup_can_frame *frame);
extern int obtain_module_ethernet_status(int mod, struct aup_can_frame *);

#endif

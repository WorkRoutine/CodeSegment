#ifndef _TRANSFER_H
#define _TRANSFER_H

#define BUFFER_SIZE   4096

#define monitor_launch() while(1)

extern int monitor_send_thread(void);
extern int monitor_recv_thread(void);

#endif

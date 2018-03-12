#ifndef _UART_H
#define _UART_H

extern int set_opt(int nSpeed, int nBits, char nEvent, int nStop);

extern int uart_open(int uart);
extern void uart_close(void);
extern int uart_read(char **buf, int count);
extern int uart_write(char *buf);

#endif

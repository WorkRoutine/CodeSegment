/*
 * Process signal on CAN-To-Termnal
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <uart.h>
#include <signals.h>

/* Handle signal from system */
static do_signal(int sig)
{
    switch (sig) {
    case SIGSTOP:
        /* CTRL Z */
    case SIGINT:
        /* CTRL C */
    case SIGQUIT:
        /* CTRL \ */
    case SIGTERM:
        /* Termnal */
    case SIGKILL:
        /* Kill -9 */
        uart_close();
        exit (1);
        break;
    default:
        fprintf(stderr, "Undefined signal.\n");
        exit (1);
    }
}

/* Initialize all signal */
void signal_init(void)
{
    signal(SIGSTOP, do_signal);
    signal(SIGINT,  do_signal);
    signal(SIGQUIT, do_signal);
    signal(SIGKILL, do_signal);
    signal(SIGTERM, do_signal);
}

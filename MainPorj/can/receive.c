/*
 * Reveice message from CAN bus
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <transfer.h>
#include <can.h>

static pthread_t rtp;

int parse_transfer_char(char ch)
{
    switch (ch) {
    case '\a':
        printf("Char: \\a\n");
        break;
    case '\b':
        printf("Char: \\b\n");
        break;
    case '\f':
        printf("Char: \\f\n");
        break;
    case '\n':
        printf("Char: \\n\n");
        break;
    case '\r':
        printf("Char: \\r\n");
        break;
    case '\v':
        printf("Char: \\v\n");
        break;
    case '\t':
        printf("Char: \\t\n");
        break;
    case '\\':
        printf("Char: \\\n");
        break;
    case '\'':
        printf("Char: \'\n");
        break;
    case '\"':
        printf("Char: \"\n");
        break;
    case '\?':
        printf("Char: \?\n");
        break;
    case '\0':
        printf("Char: \\0\n");
        break;
    default:
        printf("Udef: %c\n", ch);
        break;
    }
}

static void *do_receive_message(void *arg)
{
    struct can_frame rx_frame;
    int nbytes;

    while (1) {
        /* Receive CAN frame */
        nbytes = read(can_fd, &rx_frame, sizeof(rx_frame));
        if (nbytes > 0) {
            int i;

            for (i = 0; i < rx_frame.can_dlc; i++) {
                printf("%c\n", rx_frame.data[i]);
                //parse_transfer_char(rx_frame.data[i]);
            }
        }
    }
}

/* Reveice Message monitor thread */
int monitor_recv_thread(void)
{
    int ret;

    ret = pthread_create(&rtp, NULL, do_receive_message, NULL);
    if (ret) {
        printf("Unable to create reveive monitor thread.\n");
        return -1;
    }
    return 0;
} 

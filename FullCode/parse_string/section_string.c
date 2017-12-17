/*
 * Parse by section
 *
 * (C) 2017.12 <buddy.zhang@aliyun.com>
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CAN_MAX_DLEN 8
#define MAX_CAN      16
#define TX_CANID     0x11

char *TEST_buffer = "1234567abcdefghijklmnopqrstuvwxyz";

struct can_frame
{
    unsigned int  can_id;
    unsigned char can_dlc;
    unsigned char data[CAN_MAX_DLEN];
};

struct can_frame tx_frame[MAX_CAN];

/* Send message to CAN */
int CAN_send_message(char *buffer)
{
    int size = strlen(buffer) + 1;
    int group = (size + CAN_MAX_DLEN - 1) / CAN_MAX_DLEN;
    int i = 0, j;

    if (group > MAX_CAN) {
        fprintf(stderr, "Data big that CAN buffer!\n");
        exit(1);
    }

    while (size) {
        if (size < 8 && size > 0) {
            /* CAN frame contain '\n' */
            tx_frame[i].can_id  = TX_CANID;
            tx_frame[i].can_dlc = size;
            if (size != 1)
                strncpy(tx_frame[i].data, &buffer[i * CAN_MAX_DLEN], size - 1);
            tx_frame[i].data[size - 1] = '\n';
            size = 0;
            i++;
        } else if (size >= 8) {
            /* multip CAN frame */;
            tx_frame[i].can_id = TX_CANID;
            tx_frame[i].can_dlc = CAN_MAX_DLEN;
            strncpy(tx_frame[i].data, &buffer[i * CAN_MAX_DLEN], CAN_MAX_DLEN);
            if (size == 8)
                tx_frame[i].data[CAN_MAX_DLEN - 1] = '\n';
            size -= 8;
            i++;
        } else {
            fprintf(stderr, "Bad size for TX buffer\n");
            exit(1);
        }
    }

    for (j = 0; j < i; j++) {
        int m;

        for (m = 0; m < 8; m++)
            printf("%c ", tx_frame[j].data[m]);
    }

    return 0;
}


int main(void)
{
   CAN_send_message(TEST_buffer);
   return 0;
}

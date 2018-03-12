/*
 * Can device operating
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <sys/ioctl.h>
#include <can.h>

#define BUFFER_SIZE 40
#define MAX_EVENTS  10

static struct sockaddr_can addr;
static struct ifreq ifr;
static struct can_filter rfilter[2];
static struct can_frame tx_frame[MAX_CAN];
int can_fd;
struct aup_can_frame system_can;

/*
 * Enable CAN to monitor specific node
 *
 *   @node: node number
 *
 *   @return: 0 is success.
 */
void enable_CAN_monitor(int cmdid)
{
    /* Bind socket */
    rfilter[0].can_id = cmdid;
    rfilter[0].can_mask = CAN_SFF_MASK;

    /* filter specify CAN frame  */
    setsockopt(can_fd, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter[0], 
                  sizeof(rfilter[0]));
}

/*
 * Disable CAN to monitor any node.
 */
void disable_CAN_monitor(void)
{
    /* Unbind socket */
    rfilter[0].can_id = 0;
    rfilter[0].can_mask = CAN_SFF_MASK;

    /* filter specify CAN frame  */
    setsockopt(can_fd, SOL_CAN_RAW, CAN_RAW_FILTER, NULL, 0);
}

/*
 * Open a specific CAN bus.
 *   @device: the name of can bus.
 *   @node: the name of node.
 *
 *   @return: 0 is succeed.
 */
int can_open(char *device)
{
    /* Create can socket */
    can_fd = socket(PF_CAN, SOCK_RAW | SOCK_NONBLOCK, CAN_RAW);
    if (can_fd < 0) {
        return -1;
    }
    strcpy(ifr.ifr_name, device);
    /* set can device */
    ioctl(can_fd, SIOCGIFINDEX, &ifr);
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
    /* bind to can0 */
    bind(can_fd, (struct sockaddr *)&addr, sizeof(addr));

    return 0;
}

/*
 * Close a specific CAN bus
 */
void can_close(void)
{
    disable_CAN_monitor();
    close(can_fd);
}

/* Send Command Message to CAN-Bus */
int CAN_send_messageC(char *buffer, struct aup_can_frame *frame)
{
    int bytes;
    
    /* Send first CAN frame */
    bytes = write(can_fd, &frame->cx, sizeof(frame->cx));
    if (bytes != sizeof(frame->cx)) {
        printf("Broken on send first CAN frame\n");
        return -1;
    }
    return 0;
}

/* Send Data Message to CAN-Bus */
int CAN_send_messageD(char *buffer, struct aup_can_frame *frame)
{
    int size = strlen(buffer) + 1;
    int group = (size + CAN_MAX_DLEN - 1) / CAN_MAX_DLEN;
    int i = 0, j;
    int bytes;
    struct can_frame can[MAX_CAN];

    if (group > MAX_CAN) {
        printf("Data big that CAN buffer!\n");
        return -1;
    }

    while (size) {
        if (size < 8 && size > 0) {
            /* CAN frame contain '\n' */
            can[i].can_id  = frame->dat_id + 1;
            can[i].can_dlc = size;
            if (size != 1)
                strncpy(can[i].data, &buffer[i * CAN_MAX_DLEN], size - 1);
            can[i].data[size - 1] = '\n';
            size = 0;
            i++;
        } else if (size >= 8) {
            /* multip CAN frame */;
            can[i].can_id  = frame->dat_id + 1;
            can[i].can_dlc = CAN_MAX_DLEN;
            strncpy(can[i].data, &buffer[i * CAN_MAX_DLEN], CAN_MAX_DLEN);
            if (size == 8)
                can[i].data[CAN_MAX_DLEN - 1] = '\n';
            size -= 8;
            i++;
        } else {
            printf("Bad size for TX buffer\n");
            return -1;
        }
    }

    /* Send message */
    for (j = 0; j < i; j++) {
        bytes = write(can_fd, &can[j], sizeof(can[j]));
        if (bytes != sizeof(can[j])) {
            printf("Broken send message\n");
            return -1;
        }
    }
    return 0;
}

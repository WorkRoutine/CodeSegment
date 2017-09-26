/*
 * base select demo code
 *
 * (C) 2017.09 <buddy.zhang@aliyun.com>
 */
#include <sys/types.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    char buffer[128];
    int result, nread;
    fd_set inputs, testfds;
    struct timeval timeout;
    FD_ZERO(&inputs);
    FD_SET(0, &inputs);

    while (1) {
        testfds = inputs;
        timeout.tv_sec = 2;
        timeout.tv_usec = 500000;
        result = select(FD_SETSIZE, &testfds, (fd_set *)0, (fd_set *)0, &timeout);
        switch (result) {
        case 0:
            printf("timeout.\n");
            break;
        case -1:
            perror("select");
            return -1;
        default:
            if (FD_ISSET(0, &testfds)) {
                ioctl(0, FIONREAD, &nread);
                if (nread == 0) {
                    printf("keyboard done.\n");
                    return -1;
                }
                nread = read(0, buffer, nread);
                buffer[nread] = 0;
                printf("read %d from keyboard: %s\n", nread, buffer);
            }
            break;
        }
    }
    return 0;
}

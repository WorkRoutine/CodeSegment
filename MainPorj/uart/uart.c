#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>

static int default_speed = 115200;
static int default_bits = 8;
static int default_stop = 1;

static int uart_fd;

/*
 * Terminal setup
 */
int set_opt(int nSpeed, int nBits, char nEvent, int nStop)
{
    struct termios newtio, oldtio;
  
    int fd = uart_fd;

    if (nSpeed == 0) {
        nSpeed = default_speed;
    }

    if (nBits == 0) {
       nBits = default_bits;
    }

    if (nStop == 0) {
        nStop = default_stop;
    }

    if (tcgetattr(fd, &oldtio) != 0) { 
        perror("SetupSerial 1");
        return -1;
    }
    bzero(&newtio, sizeof(newtio));
    newtio.c_cflag |= CLOCAL | CREAD; 
    newtio.c_cflag &= ~CSIZE; 

    switch(nBits) {
    case 7:
        newtio.c_cflag |= CS7;
        break;
    case 8:
        newtio.c_cflag |= CS8;
        break;
    }

    switch(nEvent) {
    case 'O':
        newtio.c_cflag |= PARENB;
        newtio.c_cflag |= PARODD;
        newtio.c_iflag |= (INPCK | ISTRIP);
        break;
    case 'E': 
        newtio.c_iflag |= (INPCK | ISTRIP);
        newtio.c_cflag |= PARENB;
        newtio.c_cflag &= ~PARODD;
        break;
    case 'N': 
        newtio.c_cflag &= ~PARENB;
        break;
    }

    switch(nSpeed) {
    case 2400:
        cfsetispeed(&newtio, B2400);
        cfsetospeed(&newtio, B2400);
        break;
    case 4800:
        cfsetispeed(&newtio, B4800);
        cfsetospeed(&newtio, B4800);
        break;
    case 9600:
        cfsetispeed(&newtio, B9600);
        cfsetospeed(&newtio, B9600);
        break;
    case 115200:
        cfsetispeed(&newtio, B115200);
        cfsetospeed(&newtio, B115200);
        break;
    default:
        cfsetispeed(&newtio, B9600);
        cfsetospeed(&newtio, B9600);
        break;
    }

    /* input flags */
    newtio.c_iflag = IGNPAR;

    /* output flags */
    newtio.c_oflag = 0;

    /* local flag */
    newtio.c_lflag = 0;

    if(nStop == 1)
        newtio.c_cflag &= ~CSTOPB;
    else if ( nStop == 2 )
        newtio.c_cflag |= CSTOPB;
    newtio.c_cc[VTIME] = 50;
    newtio.c_cc[VMIN] = 0;
    tcflush(fd, TCIFLUSH);
  
    if((tcsetattr(fd, TCSANOW, &newtio))!=0) {
        perror("com set error");
        return -1;
    }
    return 0;
}

/*
 * Initialize and open port
 */
int uart_open(int uart)
{
    const char *uart_name[] = { "/dev/ttyS0", "/dev/ttyS1", "/dev/ttyS2"};

    uart_fd = open(uart_name[uart], O_RDWR | O_NOCTTY | O_NONBLOCK);
    if (-1 == uart_fd) {
        printf("Can't Open Serial Port %s\n", uart_name[uart]);
        return -1;
    }  

    if(fcntl(uart_fd, F_SETFL, 0) < 0) {
       ;
       // printf("fcntl failed!\n");
    }
  
    if(isatty(STDIN_FILENO) == 0) {
          ;
//        printf("standard input is not a terminal device\n");
    }

    return 0;
}

/*
 * Close uart.
 */
void uart_close(void)
{
    close(uart_fd);
}

/*
 * Read from Uart
 */
int uart_read(char **buf, int count)
{
    return read(uart_fd, *buf, count);
}

/*
 * Write to Uart
 */
int uart_write(char *buf)
{
    return write(uart_fd, buf, strlen(buf));
}

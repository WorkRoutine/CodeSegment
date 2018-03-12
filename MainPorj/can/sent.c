#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <pthread.h>
#include <transfer.h>
#include <can.h>

/* Moniter struction */
static struct termios initial_settings, new_settings;
static int peek_character = -1;
static char TX_buffer[BUFFER_SIZE];
static pthread_t txp;
/*
 * Initialize keyboard
 */
static void init_keyboard(void)
{
    tcgetattr(0, &initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag |= ICANON;
    new_settings.c_lflag |= ECHO;
    new_settings.c_lflag |= ISIG;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &new_settings);
}

static int kbhit()
{
    unsigned char ch;
    int nread;

    if (peek_character != -1)
        return 1;
    new_settings.c_cc[VMIN] = 0;
    tcsetattr(0, TCSANOW, &new_settings);
    nread = read(0, &ch, 1);
    new_settings.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &new_settings);
    if (nread == 1) {
        peek_character = ch;
        return 1;
    }
    return 0;
}

static int readch()
{
    char ch;

    if (peek_character != -1) {
        ch = peek_character;
        peek_character = -1;
        return ch;
    }
    read(0, &ch, 1);
    return 0;
}

static void close_keyboard()
{
    tcsetattr(0, TCSANOW, &initial_settings);
}

static void *do_send_message(void *arg)
{
    /* initialize keyboard */
    init_keyboard();
    for (;;) {
        char ch;
        int pos = 0;

        while (1) {
            kbhit();
            ch = readch();
            if (ch == '\r' || ch == '\n' || ch == '\0') {
                TX_buffer[pos] = '\0';
                break;
            } else {
                TX_buffer[pos++] = ch;
            }
        }
        CAN_send_messageD(TX_buffer, &system_can);
    }
    close_keyboard();
}

int monitor_send_thread(void)
{
    int ret;

    ret = pthread_create(&txp, NULL, do_send_message, NULL);
    if (ret) {
        printf("Unable to create send mointor thread.\n");
        return -1;
    }
    return 0;
}

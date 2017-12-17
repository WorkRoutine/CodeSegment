/*
 * Monitor input from keyboard
 *
 * (C) 2017.12 <buddy.zhang@aliyun.com>
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

struct termios initial_settings, new_settings;
int peek_character = -1;
char buffer[1024];

/*
 * Initialize keyboard
 */
void init_keyboard(void)
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

int kbhit()
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

int readch()
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

void close_keyboard()
{
    tcsetattr(0, TCSANOW, &initial_settings);
}

int main(void)
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
                buffer[pos] = '\0';
                break;
            } else {
                buffer[pos++] = ch;
            }
        }
        printf("%s\n[Monitor]$ ", buffer);
    }
    close_keyboard();
    return 0;
}

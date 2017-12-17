/*
 * CURSES 
 *
 * (C) 2017.12 <buddy.zhang@aliyun.com>
 *
 * gcc common.c -lncurses -o demo
 */
#include <ncurses.h>

int main(void)
{
    initscr();
    printw("Hello World!!!");
    while (1) {
    addch('A' | A_BOLD| A_UNDERLINE);
    refresh();
    }
    getchar();
    endwin();
    return 0;
}

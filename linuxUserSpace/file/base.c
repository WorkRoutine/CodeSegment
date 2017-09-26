/*
 * base file operation
 *
 * (C) 2017.09 <buddy.zhang@aliyun.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE    1024

int main(void)
{
    int fd;
    char buf[BUF_SIZE];
    int i;

    /* open file with read only */
    fd = open("base.c", O_RDONLY, S_IRUSR);
    if (fd < 0) {
        printf("failed to open file.\n");
        return -1;
    }

    /* read contents from file */
    read(fd, buf, 32);

    /* check contents */
    for (i = 0; i < 32; i++)
        printf(" %c ", buf[i]);
    printf("\n");

    /* close file */
    close(fd);
    return 0;
}

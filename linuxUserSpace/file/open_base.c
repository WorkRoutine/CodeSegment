/*
 * base open file operation
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
    int fd, fd1, fd2;
    char buf[BUF_SIZE];
    int i;

    /* open existing file with read only */
    fd = open("base.c", O_RDONLY, S_IRUSR);
    if (fd < 0) {
        printf("failed to open existing file.\n");
        return -1;
    }

    /* Open new or existing file for reading and writting, truncating to zero 
       bytes; file permission read+write for owner, nothing for all other */
    fd1 = open("mytest.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd1 < 0) {
        printf("failed to open non-existing file.\n");
        return -1;
    }

    /* Open new or existing file for writing. writes should always
       append to end of file */
    fd2 = open("myt.txt", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND,
               S_IRUSR | S_IWUSR);
    if (fd2 < 0) {
        printf("failed to open onn-existing file with write.\n");
        return -1;
    }

    /* read contents from file */
    read(fd, buf, 32);

    /* check contents */
    for (i = 0; i < 32; i++)
        printf(" %c ", buf[i]);
    printf("\n");

    /* close file */
    close(fd2);
    close(fd1);
    close(fd);
    return 0;
}

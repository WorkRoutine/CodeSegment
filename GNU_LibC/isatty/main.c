/*
 * Determine whether the file is a tty device.
 * Compile command: gcc main.c -o a
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	int fd;
	
	printf("IS a tty(0):%d\n", isatty(0));
	printf("IS a tty(1):%d\n", isatty(1));
	printf("IS a tty(2):%d\n", isatty(2));

	fd = open("./README", 0);
	printf("Is a tty(./README):%d\n", isatty(fd));
	close(fd);

	return 0;
}

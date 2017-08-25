/*
 * Compile command: gcc main.c -o a
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *s = "ABCDEFGHIJKLMN";
	char *p;

	p = strchr(s, 'G');
	printf("The start address of [%s] is:%p\n", s, (void *)(unsigned long)s);
	printf("The start address of [%s] is:%p\n", p, (void *)(unsigned long)p);

	return 0;
}


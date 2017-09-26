/*
 * Compile command: gcc main.c -o a
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char dest[200];
	const char *src = "Hello World\n";
	char *p;

	memset(dest, 0, 200);
	p = strncat(dest, src, 5);
	printf("SRC String: %s\n", src);
	printf("DEST String: %s\n", dest);
	printf("Return String: %s\n", p);

	return 0;
}

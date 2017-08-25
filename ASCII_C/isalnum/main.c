/*
 * Compile command: gcc main.c -o a
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	char c1 = 'a';
	char c2 = '#';
	char c3 = '2';

	if (isalnum(c1) != 0)
		printf(" %c is a number or alpha.\n", c1);

	if (isalnum(c2) != 0)
		printf(" %c is a number or alpha.\n", c2);

	if (isalnum(c3) != 0)
		printf(" %c is a number or alpha.\n", c3);

	return 0;
}

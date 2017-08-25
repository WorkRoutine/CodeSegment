/*
 * Compare different between char and unsigned char
 * Compile command: gcc main.c -o a
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Compare function.
 */
void fun(unsigned char v)
{
	char c = v;
	unsigned char uc = v;
	unsigned int a = c, b = uc;
	int i = c, j = uc;
	
	printf("==== Input %c====\n", v);
	printf("       Char     Unsigned char \n");
	printf("%%c  %10c %10c\n", c, uc);
	printf("%%X  %10X %10X\n", c, uc);
	printf("%%u  %10u %10u\n", a, b);
	printf("%%d  %10d %10d\n", i, j);
}

int main(int argc, char *argv[])
{
	/* 1000 0000 */
	fun(0x80); 
	/* 0111 1111 */
	fun(0x7F);

	return 0;
}

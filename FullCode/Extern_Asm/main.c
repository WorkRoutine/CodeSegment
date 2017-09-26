#include <stdio.h>

extern int sum(int a);

int test = 4;

int main(int argc, char *argv[])
{
	printf("%d\n", sum(3));	
}

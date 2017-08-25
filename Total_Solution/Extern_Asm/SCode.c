#include <stdio.h>
#include <stdlib.h>

int add(int a, int b)
{
	int _sum;

	__asm__ __volatile__(
	"movl %1, %0 \n\t"
	"add  %2, %0"
	: "=r"(_sum)
	: "r"(a), "r"(b)
	);

	return _sum;
}

int main(int argc, char *argv[])
{
	int a = 6, b = 7;

	printf("Total %d\n", add(a, b));
}

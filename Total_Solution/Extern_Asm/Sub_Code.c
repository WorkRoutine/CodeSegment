#include <stdio.h>
#include <stdlib.h>

int sub(int a, int b)
{
	int _sub;

	__asm__ __volatile(
	"movl %1, %0 \n\t"
	"sub  %2, %0"
	: "=r"(_sub)
	: "r"(a), "r"(b)
	);

	return _sub;
}

int main(int argc, char *argv[])
{
	int a = 9, b = 4;

	printf("SUB %d - %d = %d\n", a, b, sub(a, b));

	return 0;
}

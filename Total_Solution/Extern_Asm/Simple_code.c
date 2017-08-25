#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int dest;
	int value = 2;

	__asm__ __volatile__(
	"movl %1, %0"
	:"=a"(dest)
	:"c"(value)
	:"%ebx"
	);

	printf("%d\n", dest);

	return 0;
}

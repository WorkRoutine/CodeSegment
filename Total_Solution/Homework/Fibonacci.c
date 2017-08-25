#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * fibonacci function
 */
int fib(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else if (n >= 3)
		return fib(n - 1) + fib(n -2);
	else
		printf("Pls input big than zero\n");
}

int main(void)
{
	int num;

	printf("Pls input a number:\n");
	scanf("%d", &num);
	printf("fibonacci[%d] is %d\n", num, fib(num));

	return 0;
}

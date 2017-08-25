#include <stdio.h>

int main()
{
	int i;
	int total = 0;

	for (i = 0; i < 3; i++) {
		total += i;
		printf("Total is %d\n", total);
	}

	return 0;
}

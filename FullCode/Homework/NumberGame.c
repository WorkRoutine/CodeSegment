#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int target;

int main()
{
	int num;
	int count = 5;

	/* get range number */
	target = random() % 100;

	printf("Input a nunber\n");

	while(count--) {
		scanf("%d", &num);
		if (target == num) {
			printf("Congratulate!\n");
			break;
		} else if (target > num) 
			printf("Less than!\n");
		else 
			printf("Big than!\n");
	}

	printf("Target Number is %d\n", target);
	return 0;
}



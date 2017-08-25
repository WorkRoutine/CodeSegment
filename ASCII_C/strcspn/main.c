#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *str = "I have write a new platform name to specify machine.";

	printf("Total characters from start to space character: %d\n",
				(int)(unsigned long)strcspn(str, " "));
	printf("Total characters from start to specify number: %d\n",
				(int)(unsigned long)strcspn(str, "123"));
	printf("Total size of string is %d\n",
				(int)(unsigned long)strlen(str));

	return 0;}

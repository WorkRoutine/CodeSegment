#include <stdio.h>

void foobar(int i)
{
	printf("Printing from SharedLibrary.so: %d\n", i);	
	sleep(-1);
}

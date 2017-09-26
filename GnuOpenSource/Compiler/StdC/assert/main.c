#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char *argv[])
{
	assert(1);
	printf("No assert\n");

	assert(0);
	printf("Bad assert\n");
	
	return 0;
}

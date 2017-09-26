#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SYMBOL_CONST     0x00000001
#define SYMBOL_CHOICE    0x00000100

int main(int argc, char *argv[])
{
	int flags;

	/**
	 * Operator: ! 
	 * Function:  Reverse and make value as 1 or 0
	 */
	flags = 0x00000101;
	printf("(flags & (SYMBOL_CONST | SYMBOL_CHOICE)) : %p\n",
		(void *)(unsigned long)((flags & (SYMBOL_CONST | SYMBOL_CHOICE))));
	printf("!(flags & (SYMBOL_CONST | SYMBOL_CHOICE)) : %p\n",
		(void *)(unsigned long)(!(flags & (SYMBOL_CONST | SYMBOL_CHOICE))));

	/**
	 * Operator: ~
	 * Function: Reverse every bits
	 */
	 flags = 0x00010101;
	 printf("Original value: %p\n",(void *)(unsigned long)flags);
	 printf("Reversal value: %p\n",(void *)(unsigned long)~flags);

	return 0;
}

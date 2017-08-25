/*
 * Get the environment value
 * Compile command: gcc main.c -o a
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *value;

	/* Get the environment */
	value = getenv("ZCONF_DEBUG");
	printf("ZCONFIG_DEBUG: %s\n", value);
	/* Add a new environment */
	putenv("DEBUG=1");
	/* Modify environment */
	putenv("ZCONF_DEBUG=C");
	/* Get the environment */
	value = getenv("ZCONF_DEBUG");
	printf("ZCONFIG_DEBUG: %s\n", value);
	value = getenv("DEBUG");
	printf("DEBUG: %s\n", value);
	
	return 0;
}

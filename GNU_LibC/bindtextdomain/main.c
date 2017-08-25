/*
 * Get the catalog that we search.
 * Compile command: gcc main.c -o a
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libintl.h>

#define DOMAIN_NAME "linux"
#define DOMAIN_PATH "/usr/share/locale"

int main(int argc, char *argv[])
{
	char *find_path;

	find_path = bindtextdomain(DOMAIN_NAME, DOMAIN_PATH);
	printf("Find the path %s\n", find_path);

	return 0;
}

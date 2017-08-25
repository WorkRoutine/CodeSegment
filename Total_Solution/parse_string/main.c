
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *src;
	char *Demo_string = "buddy/$ballar/$sharlly";

	/* Search specific character and get address */
	while ((src = strchr(Demo_string, '$'))) {
		char *p;
		char name[200];

		/* Initialize */
		memset(name, 0, 200);

		/* Get the string [Demo_string[0] - '$'] */
		strncat(name, Demo_string, src - Demo_string);
		printf("[Demo_string[0] - '$']: %s\n", name);
		src++;

		/* Prase the string */
		p = name;
		while (isalnum(*src) || *src == '_') 
			*p++ = *src++;
		*p = '\0';
		printf("The prase_string is %s\n", name);

		/* Loop */
		Demo_string = src;
	}

	return 0;
}

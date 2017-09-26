#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRING_SIZE 16
char *text;
int str_size;
int asize;

/*
 * Apply memory.
 */
void new_string(void)
{
	text  = (char *)malloc(STRING_SIZE);
	asize = STRING_SIZE;
	str_size = 0;
	*text = '\0';
}

/*
 * Append string.
 */
void append_string(const char *str, int size)
{
	int new_size = str_size + size + 1;

	if (new_size > asize) {
		new_size += STRING_SIZE - 1;
		new_size &= -STRING_SIZE;
		text = realloc(text, new_size);
		asize = new_size;
	}
	memcpy(text + str_size, str, size);
	str_size += size;
	text[str_size] = '\0';
}

/*
 * Dump string.
 */
void dump(void)
{
	printf("String: %s\n", text);
}

int main(int argc, char *argv[]) 
{
	char *string;

	/* create a string */
	new_string();

	string = "Hello World";
	append_string(string, strlen(string));
	dump();

	string = "New World";
	append_string(string, strlen(string));
	dump();
	
	string = "Come here";
	append_string(string, strlen(string));
	dump();

	string = "Welcome here";
	append_string(string, strlen(string));
	dump();

	free(text);
}

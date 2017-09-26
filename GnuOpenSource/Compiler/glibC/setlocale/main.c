/*
 * How programs set the Locale
 * Compile command: gcc main.c -o setLocale
 */
#include <stddef.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void with_other_locale(char *new_locale, void (*subroutine)(int), int argument)
{
	char *old_locale, *saved_locale;
	char *new;

	/* Get the name of the current locale. */
	old_locale = setlocale(LC_ALL, NULL);

	/* Copy the name so it won't be clobbered by setlocale. */
	saved_locale = strdup(old_locale);
	if (saved_locale == NULL)
		printf("Out of memory\n");

	printf("The pre-locale is %s\n", saved_locale);
	/* Now change the locale and do some stuff with it */
	new = setlocale(LC_ALL, new_locale);
	(*subroutine)(argument);
	printf("The new locale is:%s\n", new);

	/* Restore the original locale */
	setlocale(LC_ALL, saved_locale);
	free(saved_locale);
}

void display(int n)
{
	printf("The test is %d\n", n);
}

int main(int argc, char *argv[])
{
	/* Set the locale */
	with_other_locale("", display, 2);
}

/*
 * Set the domain.
 * Compile command: gcc main.c -o a
 * You can use: xgettext -k_ main.c
 */
#include <stdio.h>
#include <locale.h>
#include <libintl.h>

#define _(string) gettext(string)
#define LOCALE_NAME "linux"
#define LOCALE_PATH "language"

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");
	bindtextdomain(LOCALE_NAME, LOCALE_PATH);
	textdomain(LOCALE_NAME);
	printf(_("Hello World\n"));
	return 0;
}

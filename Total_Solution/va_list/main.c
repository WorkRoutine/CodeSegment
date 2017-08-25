/*
 * Parse variable argument list.
 * Compile command: gcc main.c -o a
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/*
 * Parse one argument.
 * @i: the first argument.
 * @...: variable argument.
 */
void parse_one_argument(int i, ...) 
{
	va_list ap;
	int v;

	va_start(ap, i);
	v = va_arg(ap, int);
	printf("Int argument is %d\n", v);
	va_end(ap);

}

/*
 * Parse more arguments.
 * @n: the number of argument.
 * @...: variable arugment.
 */
void parse_more_argument(int n, ...)
{
	va_list ap;
	int i;

	va_start(ap, n);
	for (i = 0; i < n; i++) 
		printf("The argument_list[%d] %d\n", i, va_arg(ap, int));
	va_end(ap);
}

/*
 * Parse specify argument.
 * @n: the order of argument.
 */
void parse_specify_argument(int n, ...)
{
	va_list ap;
	int num;
	int save_n = n;

	va_start(ap, n);
	while (--n)
		va_arg(ap, int);
	num = va_arg(ap, int);
	printf("The %d argument is %d\n", save_n, num);
	va_end(ap);
}

/*
 * Parse a argument list of variable string.
 * @fmt: format string.
 * @...: variable argument.
 */
void parse_string(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
}

int main(int argc, char *argv[])
{
	/* Parse a argument. */
	parse_one_argument(200, 300, 'G', 500);

	/* Parse more argument. */
	parse_more_argument(4, 1, 2, 3, 4, 5, 6);

	/* Parse specify argument. */
	parse_specify_argument(3, 1, 2, 3, 4, 5, 6);

	/* Parse a format string. */
	parse_string("Parse stirng line:%d function:%s\n", __LINE__, __func__);
	return 0;
}

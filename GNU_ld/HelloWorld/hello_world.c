#include <stdio.h>

#define MAX 50

/* Specify linker symbol */
extern char __executable_start[];
extern char etext[], _etext[], __etext[];
extern char edata[], _edata[];
extern char end[], _end[];

/* Strong and weak symbol */
int weak;
int strong = 2;
__attribute__((weak)) weak2 = 2;

//__attribute__((weakref)) void fool();

int global_init_var = 84;
int global_uninit_var;
int global_zero_var = 0;
const int const_var = 32;
const int const_zero_var = 0;

__attribute__((section("FOO"))) int self_section_var = 48;

int func(int i)
{
	printf("%d\n", i);	
}

void show_link_info(void)
{
	printf("Executable Start %p\n", __executable_start);
	printf("Text End %p %p %p\n", etext, _etext, __etext);
	printf("Data End %p %p\n", edata, _edata);
	printf("Executable End %p %p\n", end, _end);
}

int main()
{
	int a = MAX;
	static int local_init_val = 98;
	static int local_uninit_var;
	static int local_zero_var = 0;

	printf("Hello World %d\n", a);

	func(local_init_val);
#ifdef CONFIG_MMU
	printf("Support MMU\n");
#else
	printf("Don't support MMU\n");
#endif
#if 1
	printf("Support If\n");
#endif
	show_link_info();
	
	/* weak reference */
//	fool();
#pragma
	return 0;
}

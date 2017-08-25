/*
 * Use private link scripts
 * ld -T link.scripts
 */

char *str = "Hello Wrold\n";

void print()
{
	__asm__("movl $13, %%edx \n\t"
			"movl %0, %%ecx  \n\t"
			"movl $0, %%ebx  \n\t"
			"movl $4, %%eax  \n\t"
			"int $0x80       \n\t"
			::"r"(str): "edx", "ecx", "ebx");	
}

void exit()
{
	__asm__("movl $42, %ebx  \n\t"
			"movl $1,  %eax  \n\t"
			"int $0x80       \n\t");
}

void nomain()
{
	print();
	exit();
}

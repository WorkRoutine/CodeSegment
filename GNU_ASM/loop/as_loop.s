# This is simple loop demo
# write by Buddy
.code32
.section .data
output:
	.asciz "Total is: %d\n"
.section .text
.globl main
main:
	movl $3, %ecx
	movl $0, %eax

loop1:
	addl %ecx, %eax
	pushl %ecx
	pushl %eax
	pushl %eax
	pushl $output
	call printf
	popl %eax
	popl %ecx
	loop loop1
	movl $1, %eax
	movl $0, %ebx
	int $0x80

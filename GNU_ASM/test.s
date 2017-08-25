# A simple loop demo
# Write by Buddy
.code32
.section .data
output:
	.asciz "The total number is: %d\n"

.section .text
.globl main
main:
	nop
	movl $3, %ecx
	movl $0, %eax

loop1:
	addl %ecx, %eax
	pushl %ecx
	pushl %eax
	pushl %eax
	pushl $output
	call printf
	add $8, %esp
	popl %eax
	popl %ecx
	loop loop1
	movl $1, %eax
	movl $0, %ebx
	int $0x80

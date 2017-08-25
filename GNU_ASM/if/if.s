# This file is used to debug "if"
.code32
.section .data
output:
	.asciz "The number is: %d\n"

.section .text
.globl main
main:
	nop
	movl $200, %eax
	movl $100, %ecx
	cmpl %ecx, %eax
	jg out1
	jl out2
	pushl $0
normal:
	pushl $output
	call printf
	movl $1, %eax
	movl $0, %ebx
	int $0x80

out1:
	pushl %eax
	jmp normal

out2:
	pushl %ecx
	jmp normal


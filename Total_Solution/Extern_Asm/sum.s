#####
# 64Bit code!
.globl sum
sum:
    pushq %rbp
	movq %rsp, %rbp
	movq 8(%rbp), %rax
	add test, %rax
	leave
	ret

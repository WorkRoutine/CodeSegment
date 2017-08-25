
#define MOVE_SVC 0x13
#define I_BIT    0x80

.text
.align 4
.global begin
.type begin,function

begin:
	
	mov  r0,#I_BIT | MOVE_SVC
	msr  cpsr_c,r0

	mov  r1,#0xd2
	sub  r2,r0,r1
	ldr  sp, =irq_stack   @ set sq_irq = irq_stack
	bl   hello
	b    begin

.data
.align 4
irq_stack:
	.space 4096

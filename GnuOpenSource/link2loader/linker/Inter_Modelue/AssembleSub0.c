static int a = 5;
extern int b;
extern void sub0(void);

void sub1(void)
{
	a += 4;	
}

void sub2(void)
{
	b += 2;	
}

void sub3(void)
{
	sub1();	
}

void sub4(void)
{
	sub0();	
}

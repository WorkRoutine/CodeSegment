static int a = 4;
extern int b;
extern void sub3(void);

void sub0(void)
{
	sub3();
	return;	
}

int sub1(void)
{
	sub0();	
	a += 2;

	return a;
}

int sub4(void)
{
	b += 3;

	return b;
}

int main(void)
{
	sub1();
	sub4();
	return 0;	
}

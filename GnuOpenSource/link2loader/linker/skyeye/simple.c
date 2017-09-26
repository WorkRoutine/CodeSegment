
void hello(void)
{
	char *str = "Hello World";
	unsigned int *paddr = (unsigned int *)0xfffd001c;
	int i;

	for(i = 0 ; i < 10 ; i++)
		*paddr = str[i];

}

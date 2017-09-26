%{
#include <stdio.h>
#include <stdlib.h>
int num_num = 0, num_id = 0;
%}
INTEGER [-+]?[1-9][0-9]*
ID [a-zA-Z][a-zA-Z_0-9]*
SPACE [ /n/t]
%%
{INTEGER} { num_num++;
	printf("(num=%d)\n", atoi(yytext)); /* print value of number */
}

{ID} { num_id++;
	printf("(id=%s)\n", yytext);
}

{SPACE} |
. {
	/* Do nothing */
}
%%

int main()
{
	yylex();
	printf("num = %d, id = %d\n", num_num, num_id);
	return 0;
}

/* User must offer this function */
int yywrap()
{
	return 1;
}

%{
#include <stdio.h>	
%}

%token DIGIT LOWERCASELETTER UPPERCASELETTER OTHER STOP

%%
start:
	| start something
	;

something: DIGIT { printf("DIGIT\n");}
	| LOWERCASELETTER { printf("LOWERCASELETTER\n");}
	| UPPERCASELETTER { printf("UPPERCASELETTER\n");}
	| OTHER { printf("OTHER\n");}
	| STOP {exit(0);}
	;
%%

int main(int argc, char *argv[])
{
	/* Introduce */
	printf("Type somethin followed by Return. Type 'q' or 'Q' to end.\n");
	printf("\n");
	/* Start the parser */
	return(yyparse());
}

void yyerror(char *s)
{
	printf("yacc error: %s\n", s);
}

int yywrap()
{
	return 0;
}

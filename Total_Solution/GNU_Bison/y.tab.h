#ifndef YYTOKENTYPE
#define YYTOKENTYPE
/*
 * Put the token into the symbol table, so that GDB and other debuggers
 * know about them. 
 */
enum yytokentyppe {
	DIGIT = 258,
	LOWERCASELETTER = 259,
	UPPERCASELETTER = 260,
	OTHER = 261,
	STOP  = 262
};
#endif
/* Tokens. */
#define DIGIT 258
#define LOWERCASELETTER 259
#define UPPERCASELETTER 260
#define OTHER 261
#define STOP  262

#if !defined YYSTYPE && !defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
#define yystype YYSTYPE /* obsolescent; wiil be withdrawn */
#define YYSTYPE_IS_DECLARED 1
#define YYSTYPE_IS_TRIVIAL  1
#endif

extern YYSTYPE yylval;

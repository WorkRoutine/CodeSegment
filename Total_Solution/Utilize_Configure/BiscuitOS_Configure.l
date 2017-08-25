%option noyywrap

%{
#include "BiscuitOS_Config.h"
#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define CONFIG_PATH "./BiscuitOS.conf"

int Calc_Table[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 };

struct BiscuitOS_configure BiscuitOS_Config;

static void BiscuitOS_Set_String(const char *);
static void BiscuitOS_Set_Int(const char *);

%}

%%
[ \t]*#.*\n             { /* Comment */ }
String.*\n              { BiscuitOS_Set_String(yytext); }
Int.*\n                 { BiscuitOS_Set_Int(yytext); }
.			            { /* Ignore other */ }

%%

static void str2int(const char *str, int *value, int n)
{
    int i;

    *value = 0;
    
    for(i = 0; i < n; i++) 
        *value += (str[i] - '0') * Calc_Table[n - i - 1];  
}

/*
 * Set String Value.
 */
static void BiscuitOS_Set_String(const char *name)
{
    char *tmp;
    int len;

    tmp = strstr(name, "=") + 1;
    len = strlen(tmp);
    BiscuitOS_Config.String = (char *)malloc(len);
    strncpy(BiscuitOS_Config.String, tmp, len);
    BiscuitOS_Config.String[len - 1] = '\0';
}

/*
 * Set Int Value
 */
static void BiscuitOS_Set_Int(const char *name)
{
    char *tmp;
    int len;

    tmp = strstr(name, "=") + 1;
    len = strlen(tmp);
    str2int(tmp, &BiscuitOS_Config.Int, len - 1);
}

/*
 * Export: Get String value
 */
char *BiscuitOS_Get_String(void)
{
    return BiscuitOS_Config.String;    
}

/*
 * Export: Get Int value
 */
int BiscuitOS_Get_Int(void)
{
    return BiscuitOS_Config.Int;    
}

/*
 * Display all configure
 */
void BiscuitOS_Show_Current_Configure(void)
{
    printf("===== BiscuitOS Configure =====\n");
    printf("String:\t\t%s\n", BiscuitOS_Get_String());    
    printf("Int:\t\t%d\n",    BiscuitOS_Get_Int());    
    printf("============================\n");    
}

/*
 * Release all resource
 */
void BiscuitOS_Release(void)
{
    if (BiscuitOS_Config.String != NULL) 
        free(BiscuitOS_Config.String);   
}
/*
 * Parsing Configure file from "/etc/OrangePi_Camera.conf"
 */
int BiscuitOS_Parse_Configure(void)
{

	FILE *f = fopen(CONFIG_PATH, "r");

	if (!f) {
		perror(CONFIG_PATH);
		return -1;
	}
		
    yyrestart(f);
	yylex();
	fclose(f);

	return 0;
}


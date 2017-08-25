/*
 * Simple regular expression. 
 * Match a mail
 * Compile Command: gcc main.c -o a 
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <regex.h>

int main(int argc, char *argv[])
{
	int status, i;
	int cflags = REG_EXTENDED;
	regmatch_t pmatch[1];
	const size_t nmatch = 1;
	regex_t reg;
	const char *pattern = "^\\w+([-+.]\\w+)*@\\w+([-.]\\w+)*.\\w+([-.]\\w+)*$";
	char *buf = "buddy.zhang@aliyun.com";

	/* Compile regular express */
	regcomp(&reg, pattern, cflags);
	/* Match regular express */
	status = regexec(&reg, buf, nmatch, pmatch, 0);
	if (status == REG_NOMATCH)
		printf("No Match\n");
	else if (status == 0) {
		printf("Match:\n");
		for (i = pmatch[0].rm_so; i < pmatch[0].rm_eo; i++)
			putchar(buf[i]);
		printf("\n");
	}
	/* Free regulare express */
	regfree(&reg);
	
	return 0;
}


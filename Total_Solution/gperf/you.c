/* C code produced by gperf version 3.0.4 */
/* Command-line: gperf -t -L C third.gperf  */
/* Computed positions: -k'' */

#line 1 "third.gperf"

/* C Code for gperf */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#line 7 "third.gperf"
struct node 
{
	char name[20];
	char ch;
	int num;
};

#define TOTAL_KEYWORDS 4
#define MIN_WORD_LENGTH 4
#define MAX_WORD_LENGTH 7
#define MIN_HASH_VALUE 4
#define MAX_HASH_VALUE 7
/* maximum key range = 4, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
/*ARGSUSED*/
static unsigned int
hash (str, len)
     register const char *str;
     register unsigned int len;
{
  return len;
}

#ifdef __GNUC__
__inline
#if defined __GNUC_STDC_INLINE__ || defined __GNUC_GNU_INLINE__
__attribute__ ((__gnu_inline__))
#endif
#endif
struct node *
in_word_set (str, len)
     register const char *str;
     register unsigned int len;
{
  static struct node wordlist[] =
    {
      {""}, {""}, {""}, {""},
#line 16 "third.gperf"
      {"--by", 'g', 67},
#line 17 "third.gperf"
      {"--hui", 'j', 56},
#line 14 "third.gperf"
      {"--name", 'n', 40},
#line 15 "third.gperf"
      {"--uname", 'b', 60}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register const char *s = wordlist[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &wordlist[key];
        }
    }
  return 0;
}
#line 18 "third.gperf"

int main(int argc, char *argv[])
{
	struct node *node;
	int i;

	for (i = 1; i < argc; i++) {
		if ((node = in_word_set(argv[i], strlen(argv[i]))) != 0) {
			switch (node->ch) {
			case 'n':
				printf("Argument[%d]:%s value %s\n", i, argv[i], argv[i+1]);
				i++;
				break;
			case 'g':
				printf("Argument[%d]:%s value %s\n", i, argv[i], argv[i+1]);
				i++;
				break;
			}
		}
	}

	return 0;
}

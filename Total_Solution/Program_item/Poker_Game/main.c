/*
 * Poker game
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Basic data structure.
 */
struct node {
	struct node *next;
	char name[32];
	int score;
};

/*
 * Parse the string "name score".
 * If the format is "name score", we need parse the argument .
 */
void Parse_name_scare(const char *str, char *name, int *score)
{
	char *p = str;
	int stringlen = strlen(str);
	int namelen;
	int i;
	
	/* Parse the name */
	while (*str != ' ') 
		*name++ = *str++;
	*name = '\0';
	namelen = strlen(name);

	/* Parse the score */
	for (i = 0; i < (stringlen - namelen); i++) 
		*score += i * 10 * p[strlen - i];
	
}

/*
 * Create the single list.
 * Add the new node into head of list, and the oldest will push into 
 * tail of list.
 * @head: head of single list.
 * @T: the number of list member.
 */
void Create_list(struct node *head, int T)
{
	while (T--) {
		struct node *node = (struct node *)malloc(sizeof(*node));

		node->name = NULL;
		node->score = 0;
		node->next = head->next;
		head->next = node;
	}
}

/*
 * Delete the single list.
 * The purpose is free the memory, it will not over the memory limit 65536K
 * @head: the head of single list.
 */
void Delete_list(struct node *head)
{
	struct node *p;
	while (head->next) {
		p = head->next;
		head->next = p->next;
		free(p);
	}
}

int main()
{
	return 0;
}

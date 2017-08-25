/*
 * Invert a single list.
 * Compile Command: gcc main.c -o a  
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Basic data */
struct node 
{
	struct node *next;
	int n;
};

/*
 * Create a single list
 * @head: Head of single list.
 */
void CreateList(struct node *head)
{
	int n;

	head->next = NULL;
	printf("Pls input the number of list\n");
	scanf("%d", &n);

	while (n--) {
		struct node *node = (struct node *)malloc(sizeof(struct node));
		int m;

		printf("Pls a new number.\n");
		scanf("%d", &m);
		node->n = m;

		/* Add node into head of single list */
		node->next = head->next;
		head->next = node;
	}
}

/*
 * Delete a single list.
 * @head: head of single list.
 */
void DeleteList(struct node *head)
{
	struct node *node;

	while (head->next) {
		node = head->next;
		head->next = node->next;
		free(node);
	}
}

/*
 * Dump all node
 */
void DumpList(struct node *head)
{
	struct node *node = head->next;
	while (node) {
		printf("->%d ", node->n);
		node = node->next;
	}
	printf("\n");
}

/*
 * Invert a single list.
 * @head: head of single list.
 */
void InvertList(struct node *head)
{
	struct node *np = head->next;
	struct node *nextp = NULL;
	struct node *prevp = NULL;

	do {
		nextp = np->next;
		np->next = prevp;
		prevp = np;
		np = nextp;
	} while (np);
	head->next = prevp;
}

int main(int argc, char *argv[])
{
	struct node head = { .next = NULL};

	/* Create single list */
	CreateList(&head);

	/* Dump single list */
	DumpList(&head);

	/* Invert single list */
	InvertList(&head);
	DumpList(&head);

	/* Delete single list */
	DeleteList(&head);

	return 0;
}

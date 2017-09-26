/*
 * Loop all list with different pointer.
 * Compile command: gcc main.c -o a
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

/* base data */
struct node {
	struct node *next;
	int num;
};

/* 
 * Create the single list.
 */
void Create_Single_list(struct node *head, int count)
{
	while (count--) {
		struct node *node = (struct node *)malloc(sizeof(*node));
		
		node->next = head->next;
		head->next = node;
		node->num = count + 100;
	}
}

/*
 * Delete the single list.
 */
void Delete_Single_list(struct node *head)
{
	struct node *node;

	while (head->next) {
		node = head->next;
		head->next = node->next;

		free(node);
	}
}

int main(int argc, char *argv[])
{
	struct node head = { .next = NULL };
	struct node **p;
	struct node *q;

    /* Create single list */
	Create_Single_list(&head, 10);

	printf("1th pointer loop single list\n");
	/* Loop list by 1st pointer */
	for (q = head.next; q; q = q->next)
		printf(" %d", q->num);
	
	printf("\n2th pointer loop single list\n");
	/* Loop list by 2th pointer */
	for (p = &head.next; *p; p = &(*p)->next)
		printf(" %d", (*p)->num);
	printf("\n");
	
	/* Delete single list */
	Delete_Single_list(&head);
	
	return 0;
}

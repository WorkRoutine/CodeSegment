#include <stdio.h>
#include <stdlib.h>

union node_data
{
	int data;
	char ch;
};

struct node 
{
	int number;
	union node_data left, right;
};

int main(int argc, char *argv[])
{
	struct node node;

	node.left.data = 10;
	printf("Data %d\n", node.left.ch);
	
	return 0;
}

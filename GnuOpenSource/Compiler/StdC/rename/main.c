#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char oldname[80];
	char newname[80];

	/* Get old name */
	printf("Input old name\n");
	scanf("%s", oldname);

	/* Get new name */
	printf("Input new name\n");
	scanf("%s", newname);

	if (rename(oldname, newname) == 0)
		printf("Renamed %s to %s\n", oldname, newname);
	else
		printf("Rename faild\n");

	return 0;	
}

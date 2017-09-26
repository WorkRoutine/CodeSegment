/*
 * Build a hash with Opening Addressing Hash
 * Compile command: gcc main.c -o a
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Basic Date */
struct symbol 
{
	char *name;
};

/* Define fixup size of hash table */
#define NHASH 100
struct symbol symtab[NHASH];

/*
 * Calculate the hash value.
 * @sym: the name of symbol.
 */
static unsigned symhash(char *name)
{
	unsigned int hash = 0;
	unsigned c;

	while (c = *name++)
		hash = hash * 9 ^ c;

	return hash;
}

/*
 * lookup a symbol
 * @name: the name we found.
 */
struct symbol *lookup(char *name)
{
	struct symbol *sp = &symtab[symhash(name) % NHASH];
	int scount = NHASH;

	while (--scount >= 0) {
		/* The symbol has existed */
		if (sp->name && !strcmp(sp->name, name))
			return sp;

		/* The hash node is empty */
		if (!sp->name) {
			sp->name = strdup(name);
			return sp;
		}

		/* Opening address: F(x) = 1 */
		if (++sp >= symtab + NHASH)
			/* avoid overflow */
			sp = symtab;
		printf("Using Opening Address Hash\n");
	}
	/* The symbol table has overflow. */
	fputs("The symbol hash table overflow\n", stderr);
	abort();
}

/*
 * Destroy hash table.
 */
static void DestroyHashTable(void)
{
	struct symbol *sp;
	int i;

	for (i = 0; i < NHASH; i++) {
		sp = symtab + i;

		if (sp->name)
			free(sp->name);
	}
}

/*
 * Dump the hash table.
 */
static void DumpHashTable(void)
{
	struct symbol *sp;
	int i;

	for (i = 0; i < NHASH; i++) {
		sp = symtab + i;
		
		if (sp->name)
			printf("SYMTAB[%d] %s\n", i, sp->name);
	}
}

int main(int argc, char *argv[])
{
	char buffer[20];
	int n;

	printf("Pls input the number of symbol\n");
	scanf("%d", &n);

	/* Build symbol hash table */
	while (n--) {
		printf("Pls input symbol name.\n");
		scanf("%s", buffer);
		lookup(buffer);
	}
	
	/* Dump all node */
	DumpHashTable();

	/* Delete Symbol Hash Table. */
	DestroyHashTable();

	return 0;
}

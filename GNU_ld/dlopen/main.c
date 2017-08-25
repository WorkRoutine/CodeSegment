#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

#include "SharedHeader.h"

int main(int argc, char *argv[])
{
	void *pdlhander;
	char *pzerror;

	int (*lib_add)(int, int);
	int (*lib_sub)(int, int);

	pdlhander = dlopen("./libSharedSub.so", RTLD_LAZY);
	pzerror = dlerror();

	if (pzerror != 0) {
		printf("%s\n", pzerror);
		return -1;
	}

	lib_add = dlsym(pdlhander, "add");
	pzerror = dlerror();

	if (pzerror != 0) {
		printf("%s", pzerror);
		return -1;
	}

	lib_sub = dlsym(pdlhander, "sub");
	pzerror = dlerror();

	if (pzerror != 0) {
		printf("%s", pzerror);
		return -1;
	}

	printf("1 + 1 = %d\n", lib_add(1, 1));
	printf("2 - 1 = %d\n", lib_sub(2, 1));

	dlclose(pdlhander);

	return 0;
}

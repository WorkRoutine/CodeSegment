/*
 * gcc main.c -rdynamic -ldl -o main
 */
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#define LIB_PATH  "./libmath.so"

typedef int (*lib_fun)(int,int);

int main()
{
    void *handle;
    char *error;
    lib_fun func = NULL;

    /* open the library */
    handle = dlopen(LIB_PATH, RTLD_LAZY);
    if(!handle) {
	fprintf(stderr,"%s",dlerror());
	exit(EXIT_FAILURE);
    }

    /* Clear old error information */
    dlerror();

    /* Get a function from shared library */
    *(void **)(&func) = dlsym(handle,"add");
    if((error = dlerror()) != NULL) {
	fprintf(stderr,"%s\n",error);
	exit(EXIT_FAILURE);
    }
    printf("add:%d\n",(*func)(2,7));

    func = (lib_fun)dlsym(handle,"sub");
    printf("sub:%d\n",func(9,2));

    /* Close the shared library */
    dlclose(handle);
    exit(EXIT_SUCCESS);
}

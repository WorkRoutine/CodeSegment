/*
 * Get the system information.
 * Compile command: gcc main.c -o a
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>

int main(int argc, char *argv[])
{
	struct utsname buffer;
	int fb = 0;

	fb = uname(&buffer);
	if (fb < 0) {
		printf("Can't get current system information.\n");
		return 0;
	}
	printf("================ system information ==================\n");
	printf("sysname:%s\nnodename:%s\nrelease:%s\n"
		   "version:%s\nmachine:%s\n", buffer.sysname, buffer.nodename,
			buffer.release, buffer.version, buffer.machine);

#if _UTSNAME_DOMAIN_LENGTH-0
#ifdef __USE_GNU
	printf("Domainname:%s\n", buffer.domainname);
#else
	printf("__domainname:%s\n", buffer.__domainname);
#endif
#endif
}

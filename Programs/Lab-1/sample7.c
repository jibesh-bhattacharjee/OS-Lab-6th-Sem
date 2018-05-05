#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>

main()
{
	execlp("cal","cal","2012",NULL);
	/* The execlp() system call does not return. Note that the
	following statement will not be executed */
	printf("This statement is not executed if execlp succeeds.\n");
}

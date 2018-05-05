#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	int fd[2], nbytes;
	pid_t childpid;
	char readbuffer[80];
	pipe(fd);
	if((childpid = fork()) == -1)
	{
		perror("fork");
		exit(1);
	}
	if(childpid == 0)
	{
		char string[] = "Hello, parent!\n";
		write(fd[1], string, (strlen(string)+1));
		nbytes=read(fd[0], readbuffer, sizeof(readbuffer));
		printf("Received in child: %s", readbuffer);
	}
	else
	{
		nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
		printf("Received in parent: %s", readbuffer);
		strcpy(readbuffer,"Hello, child!\n");
		write(fd[1], readbuffer, (sizeof(readbuffer)));
	}
	return(0);
}

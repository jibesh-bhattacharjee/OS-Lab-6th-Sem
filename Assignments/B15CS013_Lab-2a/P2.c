#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	FILE *f;
	f=fopen("input.txt","r");
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
		char string[100];
		int size=100;
		while(f!=EOF)
		{
			fgets(string,sizeof(string),f);
			write(fd[1], string, (strlen(string)+1));
		}
	}
	else
	{
	nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
	printf("Received in parent: %s", readbuffer);	
	}
	return(0);
}

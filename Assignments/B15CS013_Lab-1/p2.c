#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main()
{
	int pid1, x = 5;
	pid1 = fork();

	if(pid1==0)
		printf("Inside child.-->%d",getpid());
	else
		printf("Inside Parent.-->%d",getpid());
	printf("---\n%d\n", pid1);
}
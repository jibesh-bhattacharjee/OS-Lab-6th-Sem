#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() 
{
	int q; 
	printf("%d %d\n",getpid(),getppid());
	q=fork();
	printf("%d %d %d\n",getpid(),getppid(),q);
	return 0;
}

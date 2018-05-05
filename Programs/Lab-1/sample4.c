#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() 
{
	int q;	
	q=fork(); 
	if(q=0) fork();
	printf("%d %d\n",getpid(),getppid());
	sleep(1); 
	return 0; 
}

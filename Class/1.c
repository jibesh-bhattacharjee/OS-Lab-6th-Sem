#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main()
{
	int pid1, pid2, pid3, status, n1;
	
	if(pid1 = fork() != 0)
	{
		wait(&status);
		printf("\nn1 = %d",n1);
	}
	else
	{
		printf("\nEnter n1: ");
		scanf("%d", &n1);
	}

	/*

	printf("\npid1 = %d", pid1);
	
	if(pid1 != 0 ) wait(&status);
	
	if(pid1 == 0)
	{	
		//sleep(3);
		printf("\nEnter n1: ");
		scanf("%d", &n1);
	}
	else {
		wait(&status);
		printf("\nn1 = %d", n1);
	}
	*/
	
	
	//printf("\n%d\n", pid2);
	//printf("\n%d\n", pid2);

}

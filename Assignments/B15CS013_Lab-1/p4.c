#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main() 
{
	pid_t p=fork();
	fork();
	pid_t q=fork();
	
	if(p==q)
		printf("X");
	else
		printf("Y");
	return 0; 
}
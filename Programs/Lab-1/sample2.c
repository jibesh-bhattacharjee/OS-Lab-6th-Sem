#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int p, q;
	p=fork(); 
	q=fork();
	if(p=0)	fork();
	fork(); 
	printf("X\n");
	return 0;
}

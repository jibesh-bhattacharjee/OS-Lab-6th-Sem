#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() 
{
	fork();
	fork();
	fork();
	printf("good morning INDIA");
	return 0;
}

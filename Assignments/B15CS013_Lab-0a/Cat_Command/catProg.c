#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

main(int argc,char*argv[])
{
	int f,readRes;
	char buffer[2048], buffer2[2048];
	
	f=open(argv[1], O_RDONLY);

	//displaying 1st file arg
	while((readRes=read(f,buffer,sizeof(buffer)))>0) 
	{
	printf("%s",buffer);
	}

	f=open(argv[2], O_RDONLY);
	
	//displaying 2nd file arg
	while((readRes=read(f,buffer2,sizeof(buffer2)))>0) 
	{
	printf("%s",buffer2);
	}	

	exit(0);
}

/* Client Program*/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	char buf[BUFSIZ];
	int fd,n;
	/* open FIFO for writing */
	fd = open("/tmp/server", O_WRONLY);
	if (fd < 0 ) {
		perror("Open");
		exit(1);
	}
	/* read data from standard input and write to FIFO */
	while ((n=read(0,buf,BUFSIZ-1)) > 0) {
		buf[n]=0;
		if (write(fd,buf,n) < 0)
			exit(1);
		printf("Write[%d]: %s\n",getpid(),buf);
	}
	close (fd);
}
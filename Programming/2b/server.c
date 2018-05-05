/* Server Program */
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	char buf[BUFSIZ];
	int fd,n;
	/* create named pipe (FIFO), set RWX rights for user */
	mknod("/tmp/server", S_IFIFO | S_IRWXU,0);
	/* open FIFO for reading */
	fd = open("/tmp/server", O_RDONLY);
	if (fd < 0 ) {
		perror("Open");
		exit(1);
	}
	/* read data from FIFO */
	while ((n=read(fd,buf,BUFSIZ-1)) > 0) {
		buf[n]=0;
		printf("Read: %s\n",buf);
	}
	close (fd);
}
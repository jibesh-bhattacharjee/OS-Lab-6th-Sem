/* server program */
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
void main()
{
	char buf[BUFSIZ];
	int fd,i=0,j,n;
	mknod("/tmp/server", S_IFIFO | S_IRWXU,0);
	fd = open("/tmp/server", O_RDONLY);
	if (fd < 0 ) 
	{
		perror("Open");
		exit(1);
	}
	n=read(fd,buf,BUFSIZ-1);
	if(n==0) return 0;
	buf[n]=0;
	char op=buf[n-2];
	int n1=0,n2=0,last=0;
	for(i=0;i<n;i++)
	{
		if(buf[i]==' ')
		{		
			for(j=last;j<i;j++)
			{
				if(last==0)
					n1=n1*10+(buf[j]-'0');
				else
				n2=n2*10+(buf[j]-'0');
			}
			last=i+1;
		}
	}
	float ans;
	//printf("%d %d %c",n1,n2,op);
	switch(op)
	{
		case '+':{ans=n1+n2;
		break;
		}
		case '-':{ans=n1-n2;
		break;
		}
		case '*':{ans=n1*n2;
		break;
		}
		case '/':ans=(1.0*n1)/n2;
	}

	printf("ans=%f",ans);

	close (fd);
}



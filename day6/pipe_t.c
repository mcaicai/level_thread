#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main()
{
	int pfd[2];
	int re;
	pid_t pid;
	char buf[20];
	re = pipe(pfd);
	if(re<0)
	{
		perror("pipe");
		return 0;
	}
	pid = fork();
	if(pid<0)
	{
		perror("fork");
		return 0;
	}
	else if(pid==0)
	{
		while(1)
		{
			strcpy(buf,"hhhahahahha");
			write(pfd[1],buf,strlen(buf));	
			sleep(1);
		}
	}
	else
	{
		while(1)
		{
			re=read(pfd[0],buf,20);
			if(re>0)
			{
				printf("read pipe= %s\n",buf);
			}
		}
	}
}	



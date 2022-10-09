#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc,char* argv[])
{	
	pid_t pid;
	pid_t rpid;
	pid = fork();
	int status;
	if(pid<0)
	{
		perror("fork");
		return 0;
	}
	else if(pid == 0)
	{
		sleep(1);
		printf("child will exit\n");
		exit(2);
	}
	else if(pid >0)
	{
		rpid=wait(&status);
		printf("Get child status=%d\n",status);
	}

}


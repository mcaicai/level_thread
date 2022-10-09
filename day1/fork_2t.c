#include <stdio.h>
#include <unistd.h>


int main(int argc,char *argv[])
{
	pid_t pid;
	int i;
	for(i=0;i<5;i++)
	{
	pid = fork();
	if(pid<0)
	{
	perror("fork");
	return 0;
	}else if(pid==0){
	printf("child sleep\n"):
	sleep(5);
	break;	
	}else{
	printf("Father sleep");
	sleep(5):
	}
	
	}
	sleep(100);
}


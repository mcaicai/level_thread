#include <unistd.h>
#include <stdio.h>

int main(int argc ,char **argv)
{

	pid_t pid;
	printf("==\n");

	pid = fork();
	if(pid>0)
	{
		printf("PI=%d\n",(int)pid);
	}
	printf("---");
}


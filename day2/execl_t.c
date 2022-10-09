#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	printf("before");
	if(execlp("ls","-ls","-a","-l","./",NULL)<0)
	{
		perror("execl");
	}
	printf("after");
	
}

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *func(void *arg)
{
	printf("This is child thread\n");
	sleep(5);
	pthread_exit("thread return \n");
}

int main(int argc,char* argv[])
{
	pthread_t tid[6];
	void *retv;
	int i;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	for(i=0;i<5;i++)
	{

		pthread_create(&tid[i],&attr,func,NULL);

	}
	
	while(1){
	
		sleep(1);
	}
	
}	
	



#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *func(void *arg)
{
	printf("This is child thread\n");
	pthread_exit("thread return \n");
}

int main(int argc,char* argv[])
{
	pthread_t tid;
	void *retv;
	pthread_create(&tid,NULL,func,NULL);
	pthread_join(tid,&retv);
	printf("thread ret = %s\n",(char*)retv);
	
	sleep(1);
	
	
}	
	



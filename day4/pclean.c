#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void cleanup(void *arg)
{
	printf("clean up arg = %s\n",(char *)arg);

}




void *func(void *arg)
{
	printf("This is child thread\n");
	pthread_cleanup_push(cleanup,"abcd");

	while(1)
	{
		sleep(1);

	}
	pthread_exit("thread return \n");
	pthread_cleanup_pop(0);
}

int main(int argc,char* argv[])
{
	pthread_t tid;
	void *retv;
	int i=0;

	
	pthread_create(&tid,NULL,func,NULL);
	sleep(1);
	pthread_cancel(tid);
	pthread_join(tid,&retv);
//printf("thread ret=%s\n",(char *)retv);
	
	while(1){
	
		sleep(1);
	}
	
}	
	


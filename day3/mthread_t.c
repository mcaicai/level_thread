#include <stdio.h>
#include <pthread.h>

void *testThread(void *arg)
{
	printf("this is thread test,pid =%d ,tid=%lu\n",getpid(),pthread_self());
	printf("input arg=%d\n",(int *)arg);

	pthread_exit(NULL);
	printf("after pthread exit\n");
}

int main()
{
	
	pthread_t tid;
	int ret;
	int arg = 5;
	int i;
	for(i=0;i<5;i++)
	{
	ret = pthread_create(&tid,NULL,(void*)testThread,(void *)i);

	printf("this is main thread tid =%lu\n",tid);
	}
	sleep(1);	
}



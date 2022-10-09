#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(){
	int re;
	int fd;
	int i;
	char buf[32]={0};
	re = mkfifo("/myfifo",0666);
	if(re < 0)
	{
		perror("mkfifo");

	}	
	fd = open("/myfifo",O_WRONLY);
	if(fd<0)
	{
		perror("open");	
		return 0;
	}
	while(1)
	{
		
	
		fgets(buf,32,stdin);
		write(fd,buf,strlen(buf));
	}
}



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	//RDWR会被系统认为读写管道都OK了
  int fd = open("a.pipe",/*O_RDWR*/O_WRONLY);
	if(fd == -1) perror("open"),exit(-1);
	int i;
	for(i=0;i<100;i++){
	  write(fd,&i,sizeof(i));
		usleep(100000);//每0.1秒
	}
	close(fd);
}


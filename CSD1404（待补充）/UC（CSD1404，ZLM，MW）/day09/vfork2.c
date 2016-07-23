#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  pid_t pid = vfork();
	if(pid == 0){
		printf("child:%d\n",getpid());
		execl("/bin/ls","ls",NULL);
		//printf("execl failed\n");
		perror("execl");
	  exit(-1);//确保一旦execl()失败,子进程退出
	}
	printf("father:%d\n",getpid());
}



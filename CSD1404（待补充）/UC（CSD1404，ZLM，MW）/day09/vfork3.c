#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  pid_t pid = fork();
	if(pid == 0){
	  printf("child:pid=%d\n",getpid());
		execl("./b.out","b.out",NULL);
		perror("execl");
		exit(-1);
	}
	waitpid(pid,0,0);//确保父进程等待子进程
}



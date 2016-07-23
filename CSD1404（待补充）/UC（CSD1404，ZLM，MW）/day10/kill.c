#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void fa(int signo){
  printf("捕获了信号%d\n",signo); }
int main(){
  pid_t pid = fork();
  if(pid == 0){//子进程执行的分支
	  signal(SIGINT,fa);
		printf("child:pid=%d\n",getpid());
		while(1); }
	sleep(1);//确保子进程的signal()先执行
	kill(pid,SIGINT);
	printf("父进程发了信号2给子进程\n");
}


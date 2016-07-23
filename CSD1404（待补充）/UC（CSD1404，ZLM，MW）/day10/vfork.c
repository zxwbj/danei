#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void fa(int signo){
  printf("捕获了信号%d\n",signo);
}
int main(){
  signal(SIGINT,fa);//信号2改成自定义
	signal(SIGQUIT,SIG_IGN);//信号3被忽略
  pid_t pid = vfork();
  if(pid == 0){
	  printf("pid=%d\n",getpid());
		execl("./proc","proc",NULL);
	}
	printf("father process over\n");
}//练习：验证vfork()+execl()的效果



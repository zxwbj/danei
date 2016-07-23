#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void fa(int signo){
  printf("捕获了信号%d\n",signo);
}
int main(){
	printf("pid=%d\n",getpid());
  signal(SIGINT,fa); signal(45,fa);
  printf("普通代码，允许中断\n");sleep(15);
  printf("执行关键代码，准备屏蔽信号\n");
	sigset_t new,old;//C语言中new不是关键字
  sigemptyset(&new);
	sigaddset(&new,SIGINT);//不可靠信号,可能丢
	sigaddset(&new,45);//可靠信号，不会丢失
	//屏蔽new中的信号，把之前的信号屏蔽放入old
sigprocmask(SIG_SETMASK,&new,&old);sleep(15);
	printf("关键代码执行完毕，解除屏蔽\n");
	sigset_t pend;
	sigpending(&pe
	if(sigismember(&pend,2)) printf("信号2\n");
	if(sigismember(&pend,45))printf("信号45\n");
	sigprocmask(SIG_SETMASK,&old,NULL);
	sleep(10);
}//信号9 屏蔽没有效果



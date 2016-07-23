#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void fa(int signo){
  printf("捕获了信号%d\n",signo);
	alarm(1);
}
int main(){
	signal(SIGALRM,fa);
  alarm(5);
	//sleep(2);
	//int res = alarm(0);//取消闹钟,返回剩余秒数
	//printf("res=%d\n",res);
	while(1);
}


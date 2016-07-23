#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>

void fa(int signo){
  printf("捕获了信号%d\n",signo);
}
int main(){
  signal(SIGALRM,fa);
  struct itimerval it;
	it.it_interval.tv_sec = 1;//间隔时间的秒数
	it.it_interval.tv_usec = 100000;
  it.it_value.tv_sec = 5;//开始时间是5秒后
	it.it_value.tv_usec = 0;
  setitimer(ITIMER_REAL,&it,NULL);
	while(1);
}


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void fa(int signo){//signo是信号的值，系统搞定
  printf("捕获了信号%d\n",signo);
	//exit(0);//加上这行，自定义的也能退出进程
}//处理函数
int main(){
  printf("pid=%d\n",getpid());
  signal(SIGINT,fa);//信号2改为fa()
	//设置信号3的处理方式为忽略 判断是否出错
  if(signal(SIGQUIT,SIG_IGN) == SIG_ERR)
	  perror("signal"),exit(-1);
//signal(SIGKILL,fa);//没有效果,信号9修改无效
	while(1);
}


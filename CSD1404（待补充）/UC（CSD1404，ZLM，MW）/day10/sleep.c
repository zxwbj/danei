#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void fa(int signo){
  printf("捕获了信号%d\n",signo);
}
int main(){
	signal(SIGINT,fa);
  int res = sleep(20);
	printf("left=%d\n",res);
	printf("over\n");
}


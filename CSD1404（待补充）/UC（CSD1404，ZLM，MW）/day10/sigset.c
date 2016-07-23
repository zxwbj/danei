#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(){
  sigset_t set;
	printf("size=%d\n",sizeof(set));
	printf("set=%d\n",set);
	sigemptyset(&set); printf("set=%d\n",set);
	sigaddset(&set,2); printf("set=%d\n",set);
	sigaddset(&set,3); 
	printf("set=%d\n",set);//0000 0110 = 6
	sigaddset(&set,7); 
	printf("set=%d\n",set);//0100 0110 = 70
  sigdelset(&set,3); printf("set=%d\n",set);
	if(sigismember(&set,2))
		printf("信号2在信号集中\n");
}



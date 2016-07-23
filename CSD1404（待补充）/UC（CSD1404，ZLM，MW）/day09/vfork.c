#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  int a = 10;
	pid_t pid = vfork();//fork();
	if(pid == 0){
	  printf("child:a=%d\n",a);
		a = 20;
	  printf("child:a=%d\n",a);
		exit(0);//vfork()创建的子进程必须用exit()
	}//否则退不出去
	printf("father runing\n");
	sleep(1);
  printf("father:a=%d\n",a);
}


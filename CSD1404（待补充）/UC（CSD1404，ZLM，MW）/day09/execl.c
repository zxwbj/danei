#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  printf("begin\n");
	execl("/bin/ls","ls",NULL);//替换进程的内存
	printf("end\n");//区域，包括代码区
}


#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(){
  int* pi = sbrk(4);
	*pi = 100;
	double* pd = sbrk(8);
	*pd = 1.0;
	char* ps = sbrk(10);
	strcpy(ps,"zhangfei");
	printf("%d,%lf,%s\n",*pi,*pd,ps);
	brk(ps); brk(pd);//释放内存但不解除映射 
	printf("%d,%lf,%s\n",*pi,*pd,ps);
	brk(pi);//所有的映射都解除
	printf("%d,%lf,%s\n",*pi,*pd,ps);//段错误
}



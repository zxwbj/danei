#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
  void* p = sbrk(0);//先取当前的位置
	brk(p+4); //分配了4个字节
	brk(p+8); //再次分配了4个字节
	brk(p+4); //回收了4个字节
	int* pi = p;  *pi = 100;
	double* pd = sbrk(0);
	brk(pd+1); *pd = 1.0;
  char* ps = sbrk(0);
	brk(ps+10); strcpy(ps,"zhangfei");
	printf("pi=%p,pd=%p,ps=%p\n",pi,pd,ps);
	brk(ps); //释放字符串的空间
	brk(pd); //释放double的空间
	brk(p); //全部回收
}



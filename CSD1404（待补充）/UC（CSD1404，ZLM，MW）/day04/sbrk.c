#include <stdio.h>
#include <unistd.h>

int main(){
  void* p1 = sbrk(4);//分配4字节+映射1页
	int* pi = p1;  *pi = 10;
	int* p2 = sbrk(4);//分配 不映射
  int* p3 = sbrk(4);
  printf("p1=%p,p2=%p,p3=%p\n",p1,p2,p3);
	*(pi+1023) = 10;
	printf("*(pi+N)=%d\n",*(pi+1023));
	sbrk(-4); sbrk(-4); void* pp = sbrk(0);
	printf("pp=%p\n",pp);
  printf("pid=%d\n",getpid());
	sbrk(4093); printf("超过一页\n");
	sleep(15); printf("回到一页\n");
	sbrk(-1);
	sleep(15); printf("全部回收\n");
	sbrk(-4096);
	while(1);
}


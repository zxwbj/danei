#include <stdio.h>
#include <stdlib.h>

int main(){
  int a,b,c,d;//栈区
  printf("a=%p,b=%p,c=%p,d=%p\n",&a,&b,&c,&d);
	int* p1 = malloc(4);//分配虚拟地址,做映射
	*(p1+32*1024) = 10;//32页可用,但不规范
	printf("*(p1+N)=%d\n",*(p1+32*1024));
	printf("p1=%p\n",p1);
	int* p2 = malloc(8);//分配虚拟地址,不做映射
	int* p3 = malloc(4);
	printf("p1=%p,p2=%p,p3=%p\n",p1,p2,p3);
	*(p1-1) = 0;//把附加数据清0了
	free(p1);
	printf("pid=%d\n",getpid());
	while(1);
}


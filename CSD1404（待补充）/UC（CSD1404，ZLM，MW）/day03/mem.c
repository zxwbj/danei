#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i1 = 10;//全局区
int i2;//BSS段
static int i3 = 10;//全局区
const int i4 = 10;//只读常量区
void fa(int i5){//栈
  int i6 = 10;//栈
  static int i7 = 10;//全局
	const int i8 = 10;//栈
	int* pi = malloc(4);//指向 堆区
  char* s1 = "abc";//指向 只读常量区
	char s2[] = "abc";//指向栈,值从只读区复制
	printf("i5=%p\n",&i5);printf("i6=%p\n",&i6);
	printf("i7=%p\n",&i7);printf("i8=%p\n",&i8);
	printf("pi=%p\n",pi);printf("s1=%p\n",s1);
	printf("s2=%p\n",s2);
}
int main(){
	printf("i1=%p\n",&i1);printf("i2=%p\n",&i2);
	printf("i3=%p\n",&i3);printf("i4=%p\n",&i4);
  fa(5);
	printf("fa=%p\n",fa);//函数名就是函数指针
	printf("pid=%d\n",getpid());//取进程ID
	while(1);
	return 0;
}//cat /proc/进程ID/maps



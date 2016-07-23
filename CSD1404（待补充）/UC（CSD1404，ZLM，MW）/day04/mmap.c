#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

int main(){
  void* p = mmap(0,//首地址交给内核
		4,//映射的大小，会补足一页
		PROT_READ|PROT_WRITE,//权限
		MAP_PRIVATE|//其他进程不能访问内存
		MAP_ANONYMOUS,//物理内存,默认映射文件
		0,0);//文件描述符和偏移量，这里用不到
	if(p == (void*)-1)//MAP_FAILED
		perror("mmap"),exit(-1);//,把两个拼成一个
  *(int*)p = 100;
	printf("*p=%d\n",*(int*)p);
  munmap(p,4);
}



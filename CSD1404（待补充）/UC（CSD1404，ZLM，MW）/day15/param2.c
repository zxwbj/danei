#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* task(void* p){//把整数当指针直接传入
  int i = (int)p; printf("i=%d\n",i); }
void* task2(void* p){//一定要保证参数的有效性
  int* pi = p; sleep(1);
	printf("*pi=%d\n",*pi);  }
int main(){
  pthread_t id1,id2; int a = 100;
	pthread_create(&id1,0,task,(void*)a);
	pthread_join(id1,0);
  int* pp = malloc(4); *pp = 100;
	pthread_create(&id2,0,task2,pp);
	free(pp);
	pthread_join(id2,0);
}


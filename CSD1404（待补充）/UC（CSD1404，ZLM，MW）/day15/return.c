#include <stdio.h>
#include <pthread.h>

void* task(void* p){
  int i;
	static int sum = 0;
	for(i=1;i<11;i++) sum = sum+i;
	return &sum; }
int main(){
  pthread_t id;
  pthread_create(&id,0,task,0);
	int* res;//res是野指针
	pthread_join(id,(void**)&res);//res改变指向
	printf("*res=%d\n",*res);//指向&sum
}//res的类型和return后面的真实类型一致就ok


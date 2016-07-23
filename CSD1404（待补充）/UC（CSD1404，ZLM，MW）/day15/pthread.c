#include <stdio.h>
#include <string.h>
#include <pthread.h>

void* task(void* p){//参数和返回值不能换
  int i;
	for(i=0;i<50;i++) printf("task:%d\n",i); }
int main(){
	pthread_t id;//线程ID一般都比较大
  int res = pthread_create(&id,0,task,0);
	if(res) printf("%s\n",strerror(res));
	printf("id=%u\n",id);
  printf("m=%u\n",pthread_self());//当前线程ID
  int i;
	for(i=0;i<50;i++) printf("main:%d\n",i);
	sleep(1);//保证主线程后 结束
}


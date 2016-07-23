#include <stdio.h>
#include <pthread.h>

void* task(void* p){
  int i;
	for(i=0;i<30;i++){
	  printf("task:%d\n",i);
		usleep(100000);
	}
}
int main(){
  pthread_t id;
	pthread_create(&id,0,task,0);
	pthread_detach(id);//处于detach线程join无效
	pthread_join(id,0);
  int i;
	for(i=0;i<30;i++){
	  printf("main:%d\n",i);
		usleep(100000);
	}
}


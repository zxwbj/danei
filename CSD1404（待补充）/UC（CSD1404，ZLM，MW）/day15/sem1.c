#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

char* name[5];//人名数据
int size = 0;//人数，也相当于数组下标
sem_t sem;//1 声明
void* task(void* p){
	sem_wait(&sem);//3 加锁
  name[size] = p;
	usleep(10000);//模拟一下延时
	size++;
  sem_post(&sem);//5 解锁
}
int main(){
	sem_init(&sem,0,1);//2 初始化
	name[size] = "liubei"; size++;
  pthread_t id1,id2;
  pthread_create(&id1,0,task,"guanyu");
	pthread_create(&id2,0,task,"zhangfei");
  pthread_join(id1,0); pthread_join(id2,0);
	sem_destroy(&sem);//6 销毁
	int i;
	for(i=0;i<size;i++) printf("%s\n",name[i]);
}



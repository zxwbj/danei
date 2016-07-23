#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

sem_t sem;
void* task(void* p){
  int i = (int)p;
  printf("第%d个线程申请资源\n",i);
  sem_wait(&sem);
 	printf("第%d个线程申请成功\n",i);
  srand(time(0));
	sleep(rand()%10);//随机休眠0-9秒
  printf("第%d个线程释放资源\n",i);
	sem_post(&sem);  }
int main(){
	sem_init(&sem,0,10);
  int i;
	for(i=1;i<21;i++){
	  pthread_t id;
		pthread_create(&id,0,task,(void*)i);
	}
	sleep(19);
	sem_destroy(&sem);
}


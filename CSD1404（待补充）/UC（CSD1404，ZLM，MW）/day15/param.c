#include <stdio.h>
#include <pthread.h>

void* task(void* p){
  int* pi = p;
	printf("*pi=%d\n",*pi);
	*pi = 200;  
}
void* task2(void* p){
  double* pd = p;
	printf("s=%lf\n",3.14*(*pd)*(*pd)); }
int main(){
  pthread_t id;
	int i = 100;
	pthread_create(&id,0,task,&i);
	pthread_join(id,0);//sleep(1);
	printf("i=%d\n",i);
	double r = 1.0;
	pthread_create(&id,0,task2,&r);
	pthread_join(id,0);//sleep(1);
}//练习：写一个线程，传入圆的半径，在线程中
//计算并打印圆的面积。 3.14


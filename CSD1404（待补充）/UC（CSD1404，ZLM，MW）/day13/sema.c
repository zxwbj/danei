#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <signal.h>//1 头文件

int semid;
void fa(int signo){//2 处理函数
  semctl(semid,0,IPC_RMID);
	exit(0);  }
int main(){
	printf("按ctrl+C退出\n");
	signal(SIGINT,fa);//3 注册处理函数
  key_t key = ftok(".",100);
	semid = semget(key,1,IPC_CREAT|0666);
	if(semid == -1) perror("semget"),exit(-1);
	int res=semctl(semid,0,SETVAL,5);//最大计数5
  if(res == -1) perror("semctl"),exit(-1);
	printf("信号量集创建成功\n");
	while(1);
}//练习：使用信号删除的信号量集



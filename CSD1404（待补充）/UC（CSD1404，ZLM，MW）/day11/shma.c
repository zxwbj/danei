#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
  key_t key = ftok(".",100);//1
	if(key == -1) perror("key"),exit(-1);
  int shmid = shmget(key,4,IPC_CREAT|0666);//2
	if(shmid == -1) perror("shmget"),exit(-1);
  void* p = shmat(shmid,0,0);//3
  if(p == (void*)-1) perror("shmat"),exit(-1);
	int* pi = p;  *pi = 100;//数据存入共享内存
	shmdt(p);//5
}//练习：写shmb.c，从共享内存中读出100并打印


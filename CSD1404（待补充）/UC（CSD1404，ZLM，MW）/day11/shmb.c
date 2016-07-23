#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
  key_t key = ftok(".",100);//1
	if(key == -1) perror("ftok"),exit(-1);
  int shmid = shmget(key,0,0);//2
	if(shmid == -1) perror("shmget"),exit(-1);
  void* p = shmat(shmid,0,0);//3
  if(p == (void*)-1) perror("shmat"),exit(-1);
	int* pi = p; printf("%d\n",*pi);
	shmdt(p);//5
}


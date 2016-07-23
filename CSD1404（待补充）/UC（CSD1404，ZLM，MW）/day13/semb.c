#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

int main(){
  key_t key = ftok(".",100);
	int semid = semget(key,0,0);
	if(semid == -1) perror("semget"),exit(-1);
	int i;
  for(i=0;i<10;i++){
	  pid_t pid = fork();
    if(pid == 0){//子进程执行的分支
			printf("子进程启动，申请共享资源\n");
			struct sembuf buf;
      buf.sem_num = 0;//下标
			buf.sem_op = -1;//计数-1
			buf.sem_flg = 0;
			semop(semid,&buf,1);//数组地址等于第一
		  printf("访问共享资源\n");//个元素地址
			sleep(10); printf("退出访问共享资源\n");
			buf.sem_op = 1;
			semop(semid,&buf,1);//加1
			exit(0);
		}
	}
}



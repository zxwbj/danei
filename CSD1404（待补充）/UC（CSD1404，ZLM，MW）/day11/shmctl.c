#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
  key_t key = ftok(".",100);
	int shmid = shmget(key,0,0);
	if(shmid == -1) perror("shmget"),exit(-1);
	struct shmid_ds ds;
	shmctl(shmid,IPC_STAT,&ds);//查询到ds中
  printf("mode=%o\n",ds.shm_perm.mode);
	printf("size=%d\n",ds.shm_segsz);
  printf("nattch=%d\n",ds.shm_nattch);
	ds.shm_perm.mode = 0640;//可以修改
	ds.shm_segsz = 400;//不能修改
	shmctl(shmid,IPC_SET,&ds);//修改
	//shmctl(shmid,IPC_RMID,0);//删除
}



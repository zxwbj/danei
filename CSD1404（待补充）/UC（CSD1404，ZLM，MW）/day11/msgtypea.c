#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct Msg{
  long mtype;
	char name[100];
}msg1,msg2;
int main(){
  key_t key = ftok(".",100);
	int msgid = msgget(key,IPC_CREAT|0666);
	if(msgid == -1) perror("msgget"),exit(-1);
  msg1.mtype = 1;strcpy(msg1.name,"zhangfei");
	msgsnd(msgid,&msg1,sizeof(msg1.name),0);
  msg2.mtype = 2;strcpy(msg2.name,"guanyu");
	msgsnd(msgid,&msg2,sizeof(msg2.name),0);
}



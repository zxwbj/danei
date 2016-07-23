#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(){
  key_t key = ftok(".",100);
	int msgid = msgget(key,IPC_CREAT|0666);
	if(msgid == -1) perror("msgget"),exit(-1);
	msgsnd(msgid,"hello",5,0);
}//练习：写msgb.c，把hello从消息队列中读出来
//并打印

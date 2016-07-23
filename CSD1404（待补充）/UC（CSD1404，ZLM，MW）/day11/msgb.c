#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(){
  key_t key = ftok(".",100);
	int msgid = msgget(key,0);
	if(msgid == -1) perror("msgget"),exit(-1);
	char buf[100] = { };
  msgrcv(msgid,buf,sizeof(buf),0,
	  /*0*/IPC_NOWAIT);
	printf("buf=%s\n",buf);
}


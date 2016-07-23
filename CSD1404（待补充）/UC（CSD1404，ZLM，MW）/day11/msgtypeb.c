#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct Msg{
  long mtype;
	char name[100];
}msg;
int main(){
  key_t key = ftok(".",100);
	int msgid = msgget(key,0);
	if(msgid == -1) perror("msgget"),exit(-1);
	int res = msgrcv(msgid,&msg,
		sizeof(msg.name),/*2*/-2,0);
  printf("res=%d,name=%s\n",res,msg.name);
}



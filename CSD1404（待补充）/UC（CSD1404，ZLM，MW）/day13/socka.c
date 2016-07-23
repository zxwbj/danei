#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>

int main(){
  int sockfd = socket(AF_UNIX,SOCK_DGRAM,0);
	if(sockfd == -1) perror("socket"),exit(-1);
	struct sockaddr_un addr;
	addr.sun_family = AF_UNIX;//与socket()一致
  strcpy(addr.sun_path,"a.sock");//socket文件
	int res = bind(sockfd,
		(struct sockaddr*)&addr,sizeof(addr));
	if(res == -1) perror("bind"),exit(-1);
  printf("bind ok\n");
  char buf[100] = { };
	read(sockfd,buf,sizeof(buf));
	printf("buf=%s\n",buf); close(sockfd);
}


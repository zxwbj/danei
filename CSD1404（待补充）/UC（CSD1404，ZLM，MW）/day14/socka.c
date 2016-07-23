#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
  int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd == -1) perror("socket"),exit(-1);
	struct sockaddr_in addr;
  addr.sin_family = AF_INET;
	addr.sin_port = htons(2222);
  addr.sin_addr.s_addr = 
		inet_addr("172.40.0.10");
	int res = bind(sockfd,
		(struct sockaddr*)&addr,sizeof(addr));
  if(res == -1) perror("bind"),exit(-1);
	printf("bind ok\n");
	char buf[100] = { };
	res = read(sockfd,buf,sizeof(buf));
	if(res == -1) perror("read"),exit(-1);
	printf("res=%d,buf=%s\n",res,buf);
	close(sockfd);
}


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
  //不连接也能发送数据才是UDP的特点
	//write(sockfd,"hello",5);//没地址,发送失败
  sendto(sockfd,"hello",5,0,
		(struct sockaddr*)&addr,sizeof(addr));
	char buf[100] = {};
	read(sockfd,buf,sizeof(buf));
	printf("%s\n",buf);
	close(sockfd);
}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>//1
#include <arpa/inet.h>
int main(){
  int sockfd=socket(AF_INET,SOCK_DGRAM,0);//2
	if(sockfd == -1) perror("socket"),exit(-1);
	struct sockaddr_in addr;//3
	addr.sin_family = AF_INET;
	addr.sin_port = htons(2222); //本机转网络
	addr.sin_addr.s_addr = 
			inet_addr("172.40.0.10");//转换函数
	int res = connect(sockfd,
		(struct sockaddr*)&addr,sizeof(addr));
	if(res == -1) perror("connect"),exit(-1);
  printf("connect ok\n");
	write(sockfd,"hello",5);
	close(sockfd);
}


#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
int main(){
  int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd == -1) perror("socket"),exit(-1);
	struct sockaddr_in addr;
  addr.sin_family = AF_INET;
	addr.sin_port = htons(2222);
  addr.sin_addr.s_addr = 
		inet_addr("172.40.0.10");
	int res = connect(sockfd,
		(struct sockaddr*)&addr,sizeof(addr));
  if(res == -1) perror("connect"),exit(-1);
	printf("connect ok\n");
	char buf[100] = {};
	char retbuf[100] = {};
	while(1){
	  printf("请输入要说的话\n");
		scanf("%s",buf);//空格不好使
 	  write(sockfd,buf,strlen(buf));
		if(strcmp(buf,"bye") == 0) break;
		read(sockfd,retbuf,sizeof(retbuf));
		printf("retbuf=%s\n",retbuf);
		memset(buf,0,strlen(buf));//清空
		memset(retbuf,0,strlen(retbuf));
	}
	close(sockfd);
}


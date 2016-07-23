#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <time.h>
int sockfd;
void fa(int signo){
  printf("服务器即将关闭\n");
	close(sockfd);
	exit(0);
}
int main(){
	printf("按ctrl+C退出\n");
	signal(SIGINT,fa);
  sockfd = socket(AF_INET,SOCK_DGRAM,0);
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
	struct sockaddr_in from;
	socklen_t size = sizeof(from);
	while(1){
	  res = recvfrom(sockfd,buf,sizeof(buf),0,
		  (struct sockaddr*)&from,&size);
	  if(res == -1) perror("read"),exit(-1);
	  printf("res=%d,buf=%s\n",res,buf);
	  printf("%s发送了数据\n",
		  inet_ntoa(from.sin_addr));
		time_t curtime = time(0);
		struct tm* cur = localtime(&curtime);
    sprintf(buf,"%4d-%02d-%02d %02d:%02d:%02d"
			,cur->tm_year+1900,cur->tm_mon+1,
			cur->tm_mday,cur->tm_hour,
			cur->tm_min,cur->tm_sec);
	  sendto(sockfd,buf,strlen(buf),0,
		  (struct sockaddr*)&from,size);
	}
}


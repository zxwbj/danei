#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <signal.h>//1
int sockfd;
void fa(int signo){//2
  printf("服务器即将退出\n");
	sleep(1);
	close(sockfd);
	exit(0);
}
int main(){
	printf("按ctrl+C退出\n");
	signal(SIGINT,fa);//3
  sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd == -1) perror("socket"),exit(-1);
	struct sockaddr_in addr;
  addr.sin_family = AF_INET;
	addr.sin_port = htons(2222);
  addr.sin_addr.s_addr = 
		inet_addr("172.40.0.10");
	//解决地址被占用问题的代码
	int reuse = 1;
  setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,
		&reuse,sizeof(reuse));
  int res = bind(sockfd,
		(struct sockaddr*)&addr,sizeof(addr));
	if(res == -1) perror("bind"),exit(-1);
	printf("bind ok\n");
  listen(sockfd,100);
	struct sockaddr_in client;
	socklen_t size = sizeof(client);
	while(1){
    int fd = accept(sockfd,//阻塞,直到有客户端
		  (struct sockaddr*)&client,&size);//连接
	  printf("%s连接了上来\n",
		  inet_ntoa(client.sin_addr));
		pid_t pid = fork();
		if(pid == 0){
	    char buf[100] = {};
	    while(1){
	      int res = read(fd,buf,sizeof(buf));
				if(res <=0 ) break;//包括出错和ctrl+c
	      printf("buf=%s\n",buf);
				if(strcmp(buf,"bye")==0) break;
		    write(fd,buf,strlen(buf));
		    memset(buf,0,strlen(buf));
	    }
	    close(fd);//客户端代码改一下SOCK_STREAM
		  exit(0);}
		close(fd);
	}
}



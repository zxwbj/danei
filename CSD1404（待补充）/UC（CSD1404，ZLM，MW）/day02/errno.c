#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(){
  FILE* file = fopen("/etc/passwd1","r");
	if(file == NULL){//NULL代表出错
	  printf("errno=%d\n",errno);
		perror("fopen()");//自动加:和\n
		printf("%m\n");
		printf("%s\n",strerror(errno));
	}//返回值判断是否出错，错误信息perror()打印
	else printf("打开文件成功\n");
	if(file /*!=NULL*/) fclose(file);
}



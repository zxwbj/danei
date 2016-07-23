#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	pid_t pid1,pid2;
  pid1 = fork();
	if(pid1 > 0)//只有父进程能执行
	/*pid_t*/pid2 = fork();//语法上不是一个语句
  if(!pid1){//子进程PID1执行的分支
		printf("pid1=%d\n",getpid());
		sleep(1);
		printf("pid1 over\n"); exit(100); } 
	if(!pid2){//子进程PID2执行的分支
		printf("pid2=%d\n",getpid());
		sleep(3);
	  printf("pid2 over\n"); exit(200); }
	int status;
	pid_t pid =waitpid(/*pid2*/-1,&status,0);
	printf("等到的子进程是%d\n",pid);
	printf("status=%d\n",status);
  if(WIFEXITED(status)){//判断是否正常退出
	  printf("子进程是正常的退出\n");
    printf("退出码:%d\n",WEXITSTATUS(status));
	}
}



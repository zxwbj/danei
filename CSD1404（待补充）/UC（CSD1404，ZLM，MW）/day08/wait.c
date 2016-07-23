#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main (void) {
	pid_t pid = fork ();
	if (pid == -1) {
		perror ("fork");
		return -1;
	}
	if (pid == 0) {
		int status = 0x12345678;
		printf ("子进程：我是%d进程。"
			"我将在5秒钟后以%#x状态退出。\n",
			getpid (), status);
		sleep (5);
		return status;
	}
	printf ("父进程：我要等待子进程...\n");
	int status;
	pid = wait (&status);
	printf ("父进程：发现%d进程"
		"以%#x状态退出。\n", pid,
		WEXITSTATUS (status));
	return 0;
}

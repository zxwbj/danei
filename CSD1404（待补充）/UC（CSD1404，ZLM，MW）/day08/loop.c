#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
int main (void) {
	int i;
	for (i = 0; i < 3; ++i) {
		pid_t pid = fork ();
		if (pid == -1) {
			perror ("fork");
			return -1;
		}
		if (pid == 0) {
			printf ("子进程：我是%d进程，"
				"即将退出。\n", getpid ());
			return 0;
		}
	}
	for (;;) {
		printf ("父进程：我要等待子进程...\n");
		pid_t pid = wait (NULL);
		if (pid == -1) {
			if (errno != ECHILD) {
				perror ("wait");
				return -1;
			}
			printf ("父进程：已经没有"
				"子进程可等了。\n");
			break;
		}
		printf ("父进程：发现%d进程退出了。\n",
			pid);
	}
//getchar ();
	return 0;
}

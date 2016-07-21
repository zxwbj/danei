#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void sigint (int signum) {
	printf ("%d进程：我要死了，5555~~~~\n", getpid ());
	exit (0);
}

int main (void) {
	pid_t pid = fork ();
	if (pid == -1) {
		perror ("fork");
		return -1;
	}

	if (pid == 0) {
		printf ("%d进程：我是子进程，正在运行...\n", getpid ());

		if (signal (SIGINT, sigint) == SIG_ERR) {
			perror ("signal");
			return -1;
		}

		for (;;);

		return 0;
	}

	sleep (1);

	printf ("%d进程：我是父进程，我要杀死%d进程...\n",
		getpid (), pid);

	if (kill (pid, SIGINT) == -1) {
		perror ("kill");
		return -1;
	}

	if ((pid = wait (0)) == -1) {
		perror ("wait");
		return -1;
	}

	printf ("%d进程：%d进程已死，吼吼！\n", getpid (), pid);

	return 0;
}

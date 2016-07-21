#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sigint (int signum) {
//	signal (SIGINT, SIG_DFL);
	printf ("%d进程：收到SIGINT信号！\n", getpid ());
//	signal (SIGINT, sigint);
}

void sigkill (int signum) {
	printf ("%d进程：收到SIGKILL信号！\n", getpid ());
}

int main (void) {
	/*
	if (signal (SIGINT, SIG_IGN) == SIG_ERR) {
		perror ("signal");
		return -1;
	}
	*/
	if (signal (SIGINT, sigint) == SIG_ERR) {
		perror ("signal");
		return -1;
	}
	/*
	if (signal (SIGKILL, SIG_IGN) == SIG_ERR) {
		perror ("signal");
		return -1;
	}

	if (signal (SIGKILL, sigkill) == SIG_ERR) {
		perror ("signal");
		return -1;
	}
	*/
	printf ("%d进程：我在运行，按<Ctrl+C>没用，按<Ctrl+\\>终止...\n",
		getpid ());

	for (;;);

	return 0;
}

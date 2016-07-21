#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sigint (int signum) {
	printf ("%d进程：永别了！\n", getpid ());
	exit (0);
}

int main (void) {
	if (signal (SIGINT, sigint) == SIG_ERR) {
		perror ("signal");
		return -1;
	}

	printf ("%d进程：我要自杀...\n", getpid ());

	if (raise (SIGINT) == -1) {
		perror ("raise");
		return -1;
	}

	for (;;);

	return 0;
}

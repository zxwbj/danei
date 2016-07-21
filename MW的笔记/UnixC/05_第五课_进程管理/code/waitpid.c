#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main (void) {
	pid_t pids[3];
	int i;

	for (i = 0; i < sizeof (pids) / sizeof (pids[0]); i++) {
		pids[i] = fork ();
		if (pids[i] == -1) {
			perror ("fork");
			return -1;
		}

		if (pids[i] == 0) {
			printf ("子进程：我是%d进程。我要退出了。\n", getpid ());
			return 0;
		}
	}

	for (i = 0; i < sizeof (pids) / sizeof (pids[0]); i++) {
		printf ("父进程：我要等待%u进程...\n", pids[i]);

		pid_t pid = waitpid (pids[i], 0, 0);
		if (pid == -1) {
			perror ("waitpid");
			return -1;
		}

		printf ("父进程：发现%u进程退出了。\n", pid);
	}

	return 0;
}

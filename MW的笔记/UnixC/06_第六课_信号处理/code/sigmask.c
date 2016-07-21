#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sighand (int signum) {
	printf ("%d进程：收到%d信号！\n", getpid (), signum);
}

void updatedb (void) {
	int i;
	for (i = 0; i < 5; ++i) {
		printf ("%d进程：更新第%d条记录。\n", getpid (), i + 1);
		sleep (1);
	}
}

int main (void) {
	if (signal (SIGINT, sighand) == SIG_ERR) {
		perror ("signal");
		return -1;
	}

	if (signal (50, sighand) == SIG_ERR) {
		perror ("signal");
		return -1;
	}

	printf ("%d进程：屏蔽%d信号和%d信号。\n", getpid (), SIGINT, 50);

	sigset_t newset;

	if (sigemptyset (&newset) == -1) {
		perror ("sigemptyset");
		return -1;
	}

	if (sigaddset (&newset, SIGINT) == -1) {
		perror ("sigaddset");
		return -1;
	}

	if (sigaddset (&newset, 50) == -1) {
		perror ("sigaddset");
		return -1;
	}

	sigset_t oldset;

	if (sigprocmask (SIG_SETMASK, &newset, &oldset) == -1) {
		perror ("sigprocmask");
		return -1;
	}

	pid_t pid = fork ();
	if (pid == -1) {
		perror ("fork");
		return -1;
	}

	if (pid == 0) {
		pid_t ppid = getppid ();

		int i;
		for (i = 0; i < 5; i++) {
			printf ("%d进程：向%d进程发送%d信号和%d信号...\n", getpid (),
				ppid, SIGINT, 50);
			kill (ppid, SIGINT);
			kill (ppid, 50);
			sleep (1);
		}

		return 0;
	}

	updatedb ();

	sigset_t pendingset;

	if (sigpending (&pendingset) == -1) {
		perror ("sigpending");
		return -1;
	}

	if (sigismember (&pendingset, SIGINT))
		printf ("%d进程：发现%d信号未决。\n", getpid (), SIGINT);

	if (sigismember (&pendingset, 50))
		printf ("%d进程：发现%d信号未决。\n", getpid (), 50);

	printf ("%d进程：取消对%d信号和%d信号的屏蔽。\n", getpid (),
		SIGINT, 50);

	if (sigprocmask (SIG_SETMASK, &oldset, NULL) == -1) {
		perror ("sigprocmask");
		return -1;
	}
	/*
	if ((pid = fork ()) == -1) {
		perror ("fork");
		return -1;
	}

	if (pid == 0) {
		pid_t ppid = getppid ();

		int i;
		for (i = 0; i < 5; i++) {
			printf ("%d进程：向%d进程发送%d信号...\n", getpid (),
				ppid, 50);
			kill (ppid, 50);
		}

		return 0;
	}

	updatedb ();
	*/
	return 0;
}

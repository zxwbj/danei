#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

void sigint (int signum) {
	printf ("收到SIGINT信号！\n");
}

int main (void) {
	printf ("按<Ctrl+C>看效果...\n");

	struct sigaction act = {};
	act.sa_handler = sigint;
	act.sa_flags = SA_RESTART;

	if (sigaction (SIGINT, &act, NULL) == -1) {
		perror ("sigaction");
		return -1;
	}

	ssize_t len;
	char buf[256] = {};
//again:
	if ((len = read (STDIN_FILENO, buf, sizeof (buf))) == -1) {
//		if (errno == EINTR)
//			goto again;
		perror ("read");
		return -1;
	}

	if (write (STDOUT_FILENO, buf, len) == -1) {
		perror ("write");
		return -1;
	}

	return 0;
}

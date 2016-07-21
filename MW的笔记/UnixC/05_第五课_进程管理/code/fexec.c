#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (void) {
	pid_t pid = vfork ();
	if (pid == -1) {
		perror ("fork");
		return -1;
	}

	if (pid == 0)
		if (execlp ("ls", "ls", "-l", NULL) == -1) {
			perror ("execlp");
			exit (127);
		}

	int status;

	if (waitpid (pid, &status, 0) == -1) {
		perror ("waitpid");
		return -1;
	}

	printf ("ls进程以%#x状态退出。\n", WEXITSTATUS (status));

	if ((pid = vfork ()) == -1) {
		perror ("fork");
		return -1;
	}

	if (pid == 0) {
		char* argv[] = {"ps", "u", NULL};
		if (execvp ("ps", argv) == -1) {
			perror ("execvp");
			exit (127);
		}
	}

	if (waitpid (pid, &status, 0) == -1) {
		perror ("waitpid");
		return -1;
	}

	printf ("ps进程以%#x状态退出。\n", WEXITSTATUS (status));

	return 0;
}

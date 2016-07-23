#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main (void) {
	int fd = open ("ftab.txt", O_WRONLY |
		O_CREAT | O_TRUNC, 0664);
	if (fd == -1) {
		perror ("open");
		return -1;
	}
	pid_t pid = fork ();
	if (pid == -1) {
		perror ("fork");
		return -1;
	}
	if (pid == 0) {
		sleep (1);
		if (write (fd, "456", 3) == -1) {
			perror ("write");
			return -1;
		}
		close (fd);
		return 0;
	}
	if (write (fd, "123", 3) == -1) {
		perror ("write");
		return -1;
	}
	close (fd);
	return 0;
}

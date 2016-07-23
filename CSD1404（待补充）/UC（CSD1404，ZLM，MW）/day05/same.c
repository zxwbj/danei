#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main (void) {
	int fd1 = open ("same.txt", O_RDWR |
		O_CREAT | O_TRUNC, 0644);
	if (fd1 == -1) {
		perror ("open");
		return -1;
	}
	printf ("fd1 = %d\n", fd1);
	/*
	int fd2 = open ("same.txt", O_RDWR);
	if (fd2 == -1) {
		perror ("open");
		return -1;
	}
	*/
	int fd2 = dup2 (fd1, 100);
	if (fd2 == -1) {
		perror ("dup");
		return -1;
	}
	printf ("fd2 = %d\n", fd2);
	char const* text = "123";
	if (write (fd1, text, strlen (text) *
		sizeof (text[0])) == -1) {
		perror ("write");
		return -1;
	}
	text = "456";
	if (write (fd2, text, strlen (text) *
		sizeof (text[0])) == -1) {
		perror ("write");
		return -1;
	}
	close (fd2);
	close (fd1);
	return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main (void) {
	int fd1 = open ("d1.txt", O_WRONLY |
		O_CREAT | O_TRUNC, 0644);
	printf ("fd1 = %d\n", fd1);
	int fd2 = open ("d2.txt", O_WRONLY |
		O_CREAT | O_TRUNC, 0644);
	printf ("fd2 = %d\n", fd2);
	int fd3 = dup2 (fd1, fd2);
	printf ("fd3 = %d\n", fd3);
	write (fd1, "123", 3);
	write (fd2, "456", 3);
	write (fd3, "789", 3);
	close (fd3);
	close (fd2);
	close (fd1);
	return 0;
}

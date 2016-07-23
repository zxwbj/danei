#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
int main (void) {
	int fd = open ("chmod.txt", O_RDWR |
		O_CREAT | O_TRUNC, 0664);
	if (fd == -1) {
		perror ("open");
		return -1;
	}
//if (fchmod (fd, /*0666*/07654) == -1) {
	if (fchmod (fd, S_ISUID | S_ISGID | S_ISVTX|
		S_IRUSR | S_IWUSR |
		S_IRGRP | S_IXGRP |
		S_IROTH) == -1) {
		perror ("fchmod");
		return -1;
	}
	// rwSr-s-r-T
	close (fd);
	return 0;
}

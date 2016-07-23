#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
int rlock (int fd, off_t start, off_t len,
	int wait) {
  struct flock lock;
	lock.l_type = F_RDLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = start;
	lock.l_len = len;
	lock.l_pid = -1;
	return fcntl (fd, wait ? F_SETLKW : F_SETLK,
		&lock);
}
int ulock (int fd, off_t start, off_t len) {
	struct flock lock;
	lock.l_type = F_UNLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = start;
	lock.l_len = len;
	lock.l_pid = -1;
	return fcntl (fd, F_SETLK, &lock);
}
int main (void) {
	int fd = open ("lock.txt", O_RDONLY);
	if (fd == -1) {
		perror ("open");
		return -1;
	}
	/*
	if (rlock (fd, 0, 0, 1) == -1) {
		perror ("rlock");
		return -1;
	}
	*/
	while (rlock (fd, 0, 0, 0) == -1) {
		if (errno != EACCES && errno != EAGAIN) {
			perror ("rlock");
			return -1;
		}
		printf ("该文件已被锁定，空闲处理...\n");
		// 空闲处理...
	}
	/*
	char buf[1024];
	ssize_t readed;
	if ((readed = read (fd, buf,
		sizeof (buf))) == -1) {
		perror ("read");
		return -1;
	}
	write (STDOUT_FILENO, buf, readed);
	*/
	char buf[1];
	ssize_t readed;
	while ((readed = read (fd, buf,
		sizeof (buf))) > 0) {
		write (STDOUT_FILENO, buf, readed);
		sleep (1);
	}
	printf ("\n");
	if (ulock (fd, 0, 0) == -1) {
		perror ("ulock");
		return -1;
	}
	close (fd);
	return 0;
}

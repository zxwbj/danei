#include <stdio.h>
#include <unistd.h>
int main (void) {
	/*
	if (link ("1.txt", "link/2.txt") == -1) {
		perror ("link");
		return -1;
	}
	*//*
	if (unlink ("1.txt") == -1) {
		perror ("unlink");
		return -1;
	}
	*//*
	if (unlink ("link/2.txt") == -1) {
		perror ("unlink");
		return -1;
	}
	*//*
	if (remove ("link/2.txt") == -1) {
		perror ("remove");
		return -1;
	}
	*//*
	if (remove ("link") == -1) {
		perror ("remove");
		return -1;
	}
	*//*
	if (rename ("1.txt", "2.txt") == -1) {
		perror ("rename");
		return -1;
	}
	*//*
	if (rename ("2.txt","work/2.txt") == -1) {
		perror ("rename");
		return -1;
	}
	*//*
	if (symlink ("1.txt", "2.txt") == -1) {
		perror ("symlink");
		return -1;
	}
	*//*
	if (symlink ("2.txt", "3.txt") == -1) {
		perror ("symlink");
		return -1;
	}
	*/
	char buf[1024];
	ssize_t size = readlink ("3.txt", buf,
		sizeof (buf) - sizeof (buf[0]));
	if (size == -1) {
		perror ("readlink");
		return 0;
	}
	buf[size / sizeof (buf[0])] = '\0';
	printf ("%s\n", buf);
	return 0;
}

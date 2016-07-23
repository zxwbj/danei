#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
void pflags (int flags) {
	struct {
		int flag;
		char const* desc;
	} flist[] = {
		{O_RDONLY,   "O_RDONLY"},
		{O_WRONLY,   "O_WRONLY"},
		{O_RDWR,     "O_RDWR"},
		{O_APPEND,   "O_APPEND"},
		{O_CREAT,    "O_CREAT"},
		{O_EXCL,     "O_EXCL"},
		{O_TRUNC,    "O_TRUNC"},
		{O_NOCTTY,   "O_NOCTTY"},
		{O_NONBLOCK, "O_NONBLOCK"},
		{O_SYNC,     "O_SYNC"},
		{O_DSYNC,    "O_DSYNC"},
		{O_RSYNC,    "O_RSYNC"},
		{O_ASYNC,    "O_ASYNC"}};
	size_t i;
	for (i = 0; i < sizeof (flist) /
		sizeof (flist[0]); ++i)
		if (flist[i].flag == O_RDONLY) {
			if ((flags & O_ACCMODE)==flist[i].flag)
				printf ("%s ", flist[i].desc);
		}
	  else if (flags & flist[i].flag)
			printf ("%s ", flist[i].desc);
	printf ("\n");
}
int main (void) {
	int fd = open ("flags.txt", O_RDONLY |
		O_CREAT | O_TRUNC | O_ASYNC, 0664);
	if (fd == -1) {
		perror ("open");
		return -1;
	}
	int flags = fcntl (fd, F_GETFL);
	if (flags == -1) {
		perror ("fcntl");
		return -1;
	}
	pflags (flags);
	if (fcntl (fd, F_SETFL, O_RDWR | O_APPEND |
		O_NONBLOCK) == -1) {
		perror ("fcntl");
		return -1;
	}
	if ((flags = fcntl (fd, F_GETFL)) == -1) {
		perror ("fcntl");
		return -1;
	}
	pflags (flags);
	close (fd);
	return 0;
}

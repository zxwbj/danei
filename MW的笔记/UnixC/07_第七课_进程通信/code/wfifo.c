#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FIFO_FILE "/tmp/fifo"

int main (void) {
	printf ("创建管道...\n");

	if (mkfifo (FIFO_FILE, 0666) == -1) {
		perror ("mkfifo");
		return -1;
	}

	printf ("打开管道...\n");

	int fd = open (FIFO_FILE, O_WRONLY);
	if (fd == -1) {
		perror ("open");
		return -1;
	}

	printf ("发送数据...\n");

	for (;;) {
		printf ("> ");

		char buf[1024];
		gets (buf);

		if (! strcmp (buf, "!"))
			break;

		if (write (fd, buf, (strlen (buf) + 1) *
			sizeof (buf[0])) == -1) {
			perror ("write");
			return -1;
		}
	}

	printf ("关闭管道...\n");

	if (close (fd) == -1) {
		perror ("close");
		return -1;
	}

	printf ("删除管道...\n");

	if (unlink (FIFO_FILE) == -1) {
		perror ("unlink");
		return -1;
	}

	printf ("完成！\n");

	return 0;
}

#include <stdio.h>
#include <fcntl.h>
int main (void) {
	close (1);
	open ("hello.txt", O_WRONLY | O_CREAT |
		O_TRUNC, 0664);
	printf ("Hello, World !\n");
	return 0;
}

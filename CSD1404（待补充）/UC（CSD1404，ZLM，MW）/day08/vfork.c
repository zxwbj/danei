#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int global = 100;
int main (void) {
	int local = 200;
	int* heap = malloc (sizeof (int));
	*heap = 300;
	printf ("父进程：%d %d %d\n", global,
		local, *heap);
	pid_t pid = vfork ();
	if (pid == -1) {
		perror ("fork");
		return -1;
	}
	if (pid == 0) {
		printf ("子进程：%d %d %d\n", ++global,
			++local, ++*heap);
//	free (heap);
//	return 0;
		exit (0);
	}
//sleep (1);
	printf ("父进程：%d %d %d\n", global,
		local, *heap);
	free (heap);
	return 0;
}

#include <stdio.h>
#include <errno.h>

void foo (void) {
	FILE* fp = fopen ("none", "r");
}

int main (void) {
	foo ();
	FILE* fp = fopen ("/etc/passwd", "r");
	if (errno) {
		perror ("fopen");
		printf ("fp = %p\n", fp);
		return -1;
	}

	fclose (fp);

	return 0;
}

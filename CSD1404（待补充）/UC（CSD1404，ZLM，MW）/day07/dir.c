#include <stdio.h>
#include <unistd.h>
int main (void) {
	if (mkdir ("test", 0777) == -1) {
		perror ("mkdir");
		return -1;
	}
	/*
	if (rmdir ("test") == -1) {
		perror ("rmdir");
		return -1;
	}
	*/
	if (chdir ("test") == -1) {
		perror ("chdir");
		return -1;
	}
	char buf[1024];
	if (! getcwd (buf, sizeof (buf))) {
		perror ("getcwd");
		return -1;
	}
	printf ("%s\n", buf);
	if (chdir ("..") == -1) {
		perror ("chdir");
		return -1;
	}
	if (! getcwd (buf, sizeof (buf))) {
		perror ("getcwd");
		return -1;
	}
	printf ("%s\n", buf);
	return 0;
}

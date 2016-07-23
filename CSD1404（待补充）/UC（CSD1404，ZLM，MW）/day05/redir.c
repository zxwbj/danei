#include <stdio.h>
#include <unistd.h>
int main (void) {
	int data;
	printf ("%d %d %d\n",
	  stdin->_fileno, stdout->_fileno,
		stderr->_fileno);
	/*
	fscanf (stdin, "%d", &data);
	fprintf (stdout, "标准输出：%d\n", data);
	fprintf (stderr, "标准错误：%d\n", data);
	*/
	FILE* fp = fopen ("a.out", "r");
	printf ("%d\n", fp->_fileno);
	fclose (fp);
	printf ("%ld\n", sysconf (_SC_OPEN_MAX));
	return 0;
}

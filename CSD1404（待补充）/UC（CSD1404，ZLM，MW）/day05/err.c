#include <stdio.h>
int main (void) {
  printf ("Hello, World !\n");
	fprintf (stderr, "I'm sorry !\n");
	perror ("未知错误");
  return 0;
}

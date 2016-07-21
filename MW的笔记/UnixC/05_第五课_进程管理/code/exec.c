#include <stdio.h>
#include <unistd.h>

int main (void) {
	/*
	if (execl ("./argenv", "argenv", "hello", "world", NULL) == -1) {
		perror ("execl");
		return -1;
	}
	*//*
	char* argv[] = {"argenv", "hello", "world", NULL};
	if (execv ("./argenv", argv) == -1) {
		perror ("execv");
		return -1;
	}
	*//*
	char* envp[] = {"NAME=minwei", "PATH=/tmp", NULL};
	if (execle ("./argenv", "argenv", "hello", "world", NULL, envp) == -1) {
		perror ("execle");
		return -1;
	}
	*//*
	char* argv[] = {"argenv", "hello", "world", NULL};
	char* envp[] = {"NAME=minwei", "PATH=/tmp", NULL};
	if (execve ("./argenv", argv, envp) == -1) {
		perror ("execve");
		return -1;
	}
	*//*
	if (execlp ("argenv", "argenv", "hello", "world", NULL) == -1) {
		perror ("execlp");
		return -1;
	}
	*/
	char* argv[] = {"argenv", "hello", "world", NULL};
	if (execvp ("argenv", argv) == -1) {
		perror ("execvp");
		return -1;
	}

	return 0;
}

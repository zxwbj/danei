#include <stdio.h>

void printArgv (char* argv[]) {
	printf ("---- 命令参数 ----\n");

	while (argv && *argv)
		printf ("%s\n", *argv++);

	printf ("------------------\n");
}

void printEnvp (char* envp[]) {
	printf ("---- 环境变量 ----\n");

	while (envp && *envp)
		printf ("%s\n", *envp++);

	printf ("------------------\n");
}

int main (int argc, char* argv[], char* envp[]) {
	printArgv (argv);
	printEnvp (envp);

	return 0;
}

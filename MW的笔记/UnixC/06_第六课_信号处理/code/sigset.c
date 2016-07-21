#include <stdio.h>
#include <signal.h>

int main (void) {
	sigset_t sigset;
	printf ("%u\n", sizeof (sigset));

	sigfillset (&sigset);
	sigemptyset (&sigset);

	sigaddset (&sigset, SIGINT);
	sigaddset (&sigset, SIGQUIT);
	sigdelset (&sigset, SIGQUIT);

	printf ("信号集中%sSIGINT信号。\n",
		sigismember (&sigset, SIGINT) ? "有" : "无");

	printf ("信号集中%sSIGQUIT信号。\n",
		sigismember (&sigset, SIGQUIT) ? "有" : "无");

	return 0;
}

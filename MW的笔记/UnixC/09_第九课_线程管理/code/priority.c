#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void* thread_proc (void* arg) {
	int i;
	for (i = 0; i < 200; ++i) {
		putchar (*(char*)arg);

		int j;
		for (j = 0; j < 10000000; ++j);
	}

	return NULL;
}

int main (void) {
	setbuf (stdout, NULL);

	int error;
	/*
	pthread_attr_t attr;
	if ((error = pthread_attr_init (&attr)) != 0) {
		fprintf (stderr, "pthread_attr_init: %s\n",
			strerror (error));
		return -1;
	}

	if ((error = pthread_attr_setinheritsched (&attr,
		PTHREAD_EXPLICIT_SCHED)) != 0) {
		fprintf (stderr, "pthread_attr_setinheritsched: %s\n",
			strerror (error));
		return -1;
	}

	if ((error = pthread_attr_setschedpolicy (&attr,
		SCHED_RR)) != 0) {
		fprintf (stderr, "pthread_attr_setschedpolicy: %s\n",
			strerror (error));
		return -1;
	}

	struct sched_param sp;
	sp.sched_priority = sched_get_priority_max (SCHED_RR);
	if ((error = pthread_attr_setschedparam (&attr,
		&sp)) != 0) {
		fprintf (stderr, "pthread_attr_setschedparam: %s\n",
			strerror (error));
		return -1;
	}
	*/
	pthread_t tQuick;
	if (error = pthread_create (&tQuick, /*&attr*/NULL, thread_proc, "+")) {
		fprintf (stderr, "pthread_create: %s\n", strerror (error));
		return -1;
	}
	/*
	if ((error = pthread_attr_destroy (&attr)) != 0) {
		fprintf (stderr, "pthread_attr_destroy: %s\n",
			strerror (error));
		return -1;
	}
	*/
	pthread_t tSlow;
	if (error = pthread_create (&tSlow, NULL, thread_proc, "-")) {
		fprintf (stderr, "pthread_create: %s\n", strerror (error));
		return -1;
	}

	if ((error = pthread_join (tQuick, NULL)) != 0) {
		fprintf (stderr, "pthread_join: %s\n", strerror (error));
		return -1;
	}

	if ((error = pthread_join (tSlow, NULL)) != 0) {
		fprintf (stderr, "pthread_join: %s\n", strerror (error));
		return -1;
	}

	return 0;
}

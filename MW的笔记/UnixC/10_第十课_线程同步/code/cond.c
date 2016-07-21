#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_STOCK 20 // 仓库容量

char g_storage[MAX_STOCK]; // 仓库
size_t g_stock = 0; // 当前库存

pthread_mutex_t g_mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t g_full = PTHREAD_COND_INITIALIZER;  // 满仓
pthread_cond_t g_empty = PTHREAD_COND_INITIALIZER; // 空仓

// 显示库存
void show (const char* who, const char* op, char prod) {
	printf ("%s：", who);

	size_t i;
	for (i = 0; i < g_stock; ++i)
		printf ("%c", g_storage[i]);

	printf ("%s%c\n", op, prod);
}

// 生产者线程
void* producer (void* arg) {
	const char* who = (const char*)arg;

	for (;;) {
		pthread_mutex_lock (&g_mtx);

		if (g_stock >= MAX_STOCK) {
			printf ("\033[;;32m%s：满仓！\033[0m\n", who);
			pthread_cond_wait (&g_full, &g_mtx);
		}

		char prod = 'A' + rand () % 26;
		show (who, "<-", prod);
		g_storage[g_stock++] = prod;
		pthread_cond_signal (&g_empty);

		pthread_mutex_unlock (&g_mtx);

		usleep ((rand () % 100) * 1000);
	}

	return NULL;
}

// 消费者线程
void* customer (void* arg) {
	const char* who = (const char*)arg;

	for (;;) {
		pthread_mutex_lock (&g_mtx);

		if (! g_stock) {
			printf ("\033[;;31m%s：空仓！\033[0m\n", who);
			pthread_cond_wait (&g_empty, &g_mtx);
		}

		char prod = g_storage[--g_stock];
		show (who, "->", prod);
		pthread_cond_signal (&g_full);

		pthread_mutex_unlock (&g_mtx);

		usleep ((rand () % 100) * 1000);
	}

	return NULL;
}

int main (void) {
	srand (time (NULL));

	pthread_attr_t attr;
	int error = pthread_attr_init (&attr);
	if (error) {
		fprintf (stderr, "pthread_attr_init: %s\n", strerror (error));
		return -1;
	}

	if ((error = pthread_attr_setdetachstate (&attr,
		PTHREAD_CREATE_DETACHED)) != 0) {
		fprintf (stderr, "pthread_attr_setdetachstate: %s\n",
			strerror (error));
		return -1;
	}

	pthread_t tid;
	if ((error = pthread_create (&tid, &attr, producer,
		"生产者")) != 0) {
		fprintf (stderr, "pthread_create: %s\n", strerror (error));
		return -1;
	}

	if ((error = pthread_create (&tid, &attr, customer,
		"消费者")) != 0) {
		fprintf (stderr, "pthread_create: %s\n", strerror (error));
		return -1;
	}

	getchar ();

	return 0;
}

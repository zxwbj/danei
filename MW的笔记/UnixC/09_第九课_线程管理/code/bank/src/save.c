#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <pthread.h>
#include "../inc/bank.h"
#include "../inc/network.h"
#include "../inc/dao.h"

static int g_sockfd = -1;

void sigint (int signum) {
	printf ("存款服务：即将停止。\n");
	deinit (g_sockfd);
	exit (0);
}

void* thread_proc (void* arg) {
	pthread_detach (pthread_self ());

	int connfd = (int)arg;
	SAVE_REQUEST req;

	if (rcvreq (connfd, &req, sizeof (req)) == -1)
		return NULL;

	SAVE_RESPOND res = {""};
	ACCOUNT acc;

	if (get (req.id, &acc) == -1) {
		sprintf (res.error, "无效账号！");
		goto send_respond;
	}

	if (strcmp (req.name, acc.name)) {
		sprintf (res.error, "无效户名！");
		goto send_respond;
	}

	acc.balance += req.money;

	if (update (&acc) == -1) {
		sprintf (res.error, "更新账户失败！");
		goto send_respond;
	}

	res.balance = acc.balance;

send_respond:

	if (sndres (connfd, &res, sizeof (res)) == -1)
		return NULL;

	return NULL;
}

int main (void) {
	if (signal (SIGINT, sigint) == SIG_ERR) {
		perror ("signal");
		return -1;
	}

	if ((g_sockfd = init (TYPE_SAVE)) == -1)
		return -1;

	printf ("存款服务：启动就绪。\n");

	for (;;) {
		int connfd = accreq (g_sockfd);
		if (connfd == -1)
			continue;

		pthread_t tid;
		pthread_create (&tid, NULL, thread_proc, (void*)connfd);
	}

	return 0;
}

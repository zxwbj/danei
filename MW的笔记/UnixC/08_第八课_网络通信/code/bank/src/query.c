#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <wait.h>
#include <errno.h>
#include "../inc/bank.h"
#include "../inc/network.h"
#include "../inc/dao.h"

static int g_sockfd = -1;

void sigint (int signum) {
	printf ("查询服务：即将停止。\n");
	deinit (g_sockfd);
	exit (0);
}

void sigchld (int signum) {
	for (;;) {
		pid_t pid = waitpid (-1, 0, WNOHANG);
		if (pid == -1) {
			if (errno != ECHILD) {
				perror ("waitpid");
				exit (-1);
			}

			printf ("查询服务：全部子进程都已退出。\n");
			break;
		}

		if (pid)
			printf ("查询服务：发现%u子进程退出。\n", pid);
		else {
			printf ("查询服务：暂时没有子进程退出。\n");
			break;
		}
	}
}

int main (void) {
	if (signal (SIGINT, sigint) == SIG_ERR) {
		perror ("signal");
		return -1;
	}

	if (signal (SIGCHLD, sigchld) == SIG_ERR) {
		perror ("signal");
		return -1;
	}

	if ((g_sockfd = init (TYPE_QUERY)) == -1)
		return -1;

	printf ("查询服务：启动就绪。\n");

	QUERY_REQUEST req;

	int connfd = rcvreq (g_sockfd, &req, sizeof (req));
	if (connfd == -1)
		return -1;

	QUERY_RESPOND res = {""};
	ACCOUNT acc;

	if (get (req.id, &acc) == -1) {
		sprintf (res.error, "无效账号！");
		goto send_respond;
	}

	if (strcmp (req.name, acc.name)) {
		sprintf (res.error, "无效户名！");
		goto send_respond;
	}

	if (strcmp (req.passwd, acc.passwd)) {
		sprintf (res.error, "密码错误！");
		goto send_respond;
	}

	res.balance = acc.balance;

send_respond:

	if (sndres (connfd, &res, sizeof (res)) == -1)
		return -1;

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/bank.h"
#include "../inc/network.h"

static const char* g_server = NULL;

void menu_loop (int (*menu) (void), int (*on_menu[]) (void),
	size_t size) {
	for (;;) {
		int id = menu ();

		if (id < 0 || size <= id)
			printf ("Invalid selection !\n");
		else if (on_menu[id] () == -1)
			break;
	}
}

int main_menu (void) {
	printf ("--------\n");
	printf ("网络银行\n");
	printf ("--------\n");
	printf ("[1] 开户\n");
	printf ("[2] 清户\n");
	printf ("[3] 存款\n");
	printf ("[4] 取款\n");
	printf ("[5] 查询\n");
	printf ("[6] 转账\n");
	printf ("[0] 退出\n");
	printf ("--------\n");
	printf ("请选择：");

	int id = -1;
	scanf ("%d", &id);
	scanf ("%*[^\n]");
	scanf ("%*c");

	return id;
}

int on_quit (void) {
	printf ("谢谢使用，再见！\n");
	return -1;
}

int on_open (void) {
	OPEN_REQUEST req;

	printf ("户名：");
	scanf ("%s", req.name);
	printf ("密码：");
	scanf ("%s", req.passwd);
	printf ("金额：");
	scanf ("%lf", &req.balance);

	int sockfd = sndreq (g_server, TYPE_OPEN, &req, sizeof (req));
	if (sockfd == -1)
		return 0;

	OPEN_RESPOND res;

	if (rcvres (sockfd, &res, sizeof (res)) == -1)
		return 0;

	if (strlen (res.error)) {
		printf ("%s\n", res.error);
		return 0;
	}

	printf ("账号：%d\n", res.id);

	return 0;
}

int on_close (void) {
	CLOSE_REQUEST req;

	printf ("账号：");
	scanf ("%d", &req.id);
	printf ("户名：");
	scanf ("%s", req.name);
	printf ("密码：");
	scanf ("%s", req.passwd);

	int sockfd = sndreq (g_server, TYPE_CLOSE, &req, sizeof (req));
	if (sockfd == -1)
		return 0;

	CLOSE_RESPOND res;

	if (rcvres (sockfd, &res, sizeof (res)) == -1)
		return 0;

	if (strlen (res.error)) {
		printf ("%s\n", res.error);
		return 0;
	}

	printf ("余额：%.2lf\n", res.balance);

	return 0;
}

int on_save (void) {
	SAVE_REQUEST req;

	printf ("账号：");
	scanf ("%d", &req.id);
	printf ("户名：");
	scanf ("%s", req.name);
	printf ("金额：");
	scanf ("%lf", &req.money);

	int sockfd = sndreq (g_server, TYPE_SAVE, &req, sizeof (req));
	if (sockfd == -1)
		return 0;

	SAVE_RESPOND res;

	if (rcvres (sockfd, &res, sizeof (res)) == -1)
		return 0;

	if (strlen (res.error)) {
		printf ("%s\n", res.error);
		return 0;
	}

	printf ("余额：%.2lf\n", res.balance);

	return 0;
}

int on_withdraw (void) {
	WITHDRAW_REQUEST req;

	printf ("账号：");
	scanf ("%d", &req.id);
	printf ("户名：");
	scanf ("%s", req.name);
	printf ("密码：");
	scanf ("%s", req.passwd);
	printf ("金额：");
	scanf ("%lf", &req.money);

	int sockfd = sndreq (g_server, TYPE_WITHDRAW, &req, sizeof (req));
	if (sockfd == -1)
		return 0;

	WITHDRAW_RESPOND res;

	if (rcvres (sockfd, &res, sizeof (res)) == -1)
		return 0;

	if (strlen (res.error)) {
		printf ("%s\n", res.error);
		return 0;
	}

	printf ("余额：%.2lf\n", res.balance);

	return 0;
}

int on_query (void) {
	QUERY_REQUEST req;

	printf ("账号：");
	scanf ("%d", &req.id);
	printf ("户名：");
	scanf ("%s", req.name);
	printf ("密码：");
	scanf ("%s", req.passwd);

	int sockfd = sndreq (g_server, TYPE_QUERY, &req, sizeof (req));
	if (sockfd == -1)
		return 0;

	QUERY_RESPOND res;

	if (rcvres (sockfd, &res, sizeof (res)) == -1)
		return 0;

	if (strlen (res.error)) {
		printf ("%s\n", res.error);
		return 0;
	}

	printf ("余额：%.2lf\n", res.balance);

	return 0;
}

int on_transfer (void) {
	TRANSFER_REQUEST req;

	printf ("账号：");
	scanf ("%d", &req.id[0]);
	printf ("户名：");
	scanf ("%s", req.name[0]);
	printf ("密码：");
	scanf ("%s", req.passwd);
	printf ("金额：");
	scanf ("%lf", &req.money);
	printf ("对方账号：");
	scanf ("%d", &req.id[1]);
	printf ("对方户名：");
	scanf ("%s", req.name[1]);

	int sockfd = sndreq (g_server, TYPE_TRANSFER, &req, sizeof (req));
	if (sockfd == -1)
		return 0;

	TRANSFER_RESPOND res;

	if (rcvres (sockfd, &res, sizeof (res)) == -1)
		return 0;

	if (strlen (res.error)) {
		printf ("%s\n", res.error);
		return 0;
	}

	printf ("余额：%.2lf\n", res.balance);

	return 0;
}

int main (int argc, char* argv[]) {
	if (argc < 2) {
		printf ("用法：%s <服务器IP地址>\n", argv[0]);
		return -1;
	}

	g_server = argv[1];

	int (*on_menu[]) (void) = {on_quit, on_open, on_close,
		on_save, on_withdraw, on_query, on_transfer};
	menu_loop (main_menu, on_menu,
		sizeof (on_menu) / sizeof (on_menu[0]));

	return 0;
}

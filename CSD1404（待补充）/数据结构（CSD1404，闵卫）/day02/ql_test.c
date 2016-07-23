/* 基于链式表的队列 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ql.h"
/* 测试用例 */
int main (void) {
	QUEUE queue;
	queue_init (&queue);
	int i;
	for (i = 0; i < 10; ++i)
		queue_push (&queue, i);
	printf ("%u\n", queue_size (&queue));
	while (! queue_empty (&queue))
		printf ("%d ", queue_pop (&queue));
	printf ("\n");
	/*
	 * 输入任意行字符串，按!结束输入，
	 * 将之前输入的字符串同向打印
	 */
	char text[1024];
	for (;;) {
		gets (text);
		if (! strcmp (text, "!"))
			break;
		queue_push (&queue, (int)strcpy (malloc (
		(strlen(text)+1)*sizeof(text[0])),text));
	}
	while (! queue_empty (&queue)) {
		puts ((char const*)queue_front (&queue));
		free ((void*)queue_pop (&queue));
	}
	queue_deinit (&queue);
	return 0;
}

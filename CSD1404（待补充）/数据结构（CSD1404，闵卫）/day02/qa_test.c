/* 基于顺序表的队列 */
#include <stdio.h>
#include "qa.h"
/* 测试用例 */
int main (void) {
	QUEUE queue;
	queue_init (&queue, 4);
	int i;
	for (i = 10; i <= 40; i += 10)
		if (! queue_full (&queue))
			queue_push (&queue, i);
	for (i = 0; i < 2; ++i)
		if (! queue_empty (&queue))
			printf ("%d ", queue_pop (&queue));
	/* 10 20 */
	for (i = 50; i <= 60; i += 10)
		if (! queue_full (&queue))
			queue_push (&queue, i);
	while (! queue_empty (&queue))
		printf ("%d ", queue_pop (&queue));
	/* 30 40 50 60 */
	printf ("\n");
	queue_deinit (&queue);
	return 0;
}

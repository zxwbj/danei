/* 基于堆栈的队列 */
#include <stdio.h>
#include "qs.h"
/* 测试用例 */
int main (void) {
	QUEUE queue;
	queue_init (&queue);
	queue_push (&queue, 10);
	queue_push (&queue, 20);
	queue_push (&queue, 30);
	printf ("%d ", queue_pop (&queue)); // 10
	printf ("%d ", queue_pop (&queue)); // 20
	queue_push (&queue, 40);
	queue_push (&queue, 50);
	printf ("%d ", queue_pop (&queue)); // 30
	queue_push (&queue, 60);
	while (! queue_empty (&queue))
		printf ("%d ", queue_pop (&queue));
	// 40 50 60 
	printf ("\n");
	queue_deinit (&queue);
	return 0;
}

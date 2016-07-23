/* 基于堆栈的队列 */
#ifndef _QS_H
#define _QS_H
#include "sl.h"
/* 队列 */
typedef struct Queue {
	STACK is; /* 输入堆栈 */
	STACK os; /* 输出堆栈 */
}	QUEUE;
/* 初始化为空队列 */
void queue_init (QUEUE* queue);
/* 释放剩余节点并恢复到初始状态 */
void queue_deinit (QUEUE* queue);
/* 判断是否空 */
bool queue_empty (QUEUE* queue);
/* 压入 */
void queue_push (QUEUE* queue, int data);
/* 弹出 */
int queue_pop (QUEUE* queue);
/* 队首 */
int queue_front (QUEUE* queue);
/* 大小 */
size_t queue_size (QUEUE* queue);
#endif /* _QS_H */

/* 基于顺序表的堆栈 */
#include <stdlib.h>
#include "sa.h"
/* 分配内存并初始化为空堆栈 */
void stack_init (STACK* stack, size_t cap) {
	stack->arr = malloc (cap * sizeof (
		stack->arr[0]));
	stack->cap = cap;
	stack->top = 0;
}
/* 释放内存并恢复到初始状态 */
void stack_deinit (STACK* stack) {
	free (stack->arr);
	stack->arr = NULL;
	stack->cap = 0;
	stack->top = 0;
}
/* 判断是否满 */
bool stack_full (STACK* stack) {
	return stack->top >= stack->cap;
}
/* 判断是否空 */
bool stack_empty (STACK* stack) {
	return ! stack->top;
}
/* 压入 */
void stack_push (STACK* stack, int data) {
	stack->arr[stack->top++] = data;
}
/* 弹出 */
int stack_pop (STACK* stack) {
	return stack->arr[--stack->top];
}
/* 栈顶 */
int stack_top (STACK* stack) {
	return stack->arr[stack->top-1];
}
/* 大小 */
size_t stack_size (STACK* stack) {
	return stack->top;
}

/* 基于顺序表的堆栈 */
#include <stdio.h>
#include "sa.h"
/* 测试用例 */
int main (void) {
	STACK stack;
	stack_init (&stack, 10);
	int i = 0;
	while (! stack_full (&stack))
		stack_push (&stack, i++);
	while (! stack_empty (&stack))
		printf ("%d ", stack_pop (&stack));
	printf ("\n");
	stack_deinit (&stack);
	return 0;
}

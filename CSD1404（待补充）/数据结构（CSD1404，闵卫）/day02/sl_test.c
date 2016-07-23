/* 基于链式表的堆栈 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sl.h"
/* 测试用例 */
int main (void) {
	STACK stack;
	stack_init (&stack);
	int i;
	for (i = 0; i < 10; ++i)
		stack_push (&stack, i);
	printf ("%u\n", stack_size (&stack));
	while (! stack_empty (&stack))
		printf ("%d ", stack_pop (&stack));
	printf ("\n");
	/*
	 * 输入任意行字符串，按!结束输入，
	 * 将之前输入的字符串逆向打印
	 */
	char text[1024];
	for (;;) {
		gets (text);
		if (! strcmp (text, "!"))
			break;
		stack_push (&stack, (int)strcpy (malloc (
		(strlen(text)+1)*sizeof(text[0])),text));
	}
	while (! stack_empty (&stack)) {
		puts ((char const*)stack_top (&stack));
		free ((void*)stack_pop (&stack));
	}
	stack_deinit (&stack);
	return 0;
}

/* 简陋的堆栈 */
#include <stdio.h>
#include <stdbool.h>
int    g_arr[1024]; /* 数组 */
size_t g_top;       /* 栈顶 */
/* 判满 */
bool full (void) {
	return g_top >= sizeof (g_arr) /
		sizeof (g_arr[0]);
}
/* 判空 */
bool empty (void) {
	return ! g_top;
}
/* 压入 */
void push (int data) {
	g_arr[g_top++] = data;
}
/* 弹出 */
int pop (void) {
	return g_arr[--g_top];
}
/* 栈顶 */
int top (void) {
	return g_arr[g_top-1];
}
/* 大小 */
size_t size (void) {
	return g_top;
}
/* 测试用例 */
int main (void) {
	int i;
	for (i = 0; i < 10; ++i)
		push (i);
	while (! empty ())
		printf ("%d ", pop ());
	printf ("\n");
	return 0;
}

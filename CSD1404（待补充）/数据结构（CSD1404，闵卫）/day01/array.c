/*
 * 输入任意数量个1到100之间的整数，
 * 按照从小到大的顺序输出，
 * 不得使用任何排序算法。
 */
#include <stdio.h>
int main (void) {
	printf ("输入任意数量个1到"
		"100之间的整数：\n");
	int i, a[100] = {0};
	while (scanf ("%d", &i))
		if (1 <= i && i <= 100)
			++a[i-1];
	for (i = 0; i < sizeof(a)/sizeof(a[0]);	++i)
		while (a[i]--)
			printf ("%d ", i + 1);
	printf ("\n");
	return 0;
}

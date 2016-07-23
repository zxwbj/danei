/* 练习：对于给定数组
 * 1 2 8 9 2 4 9 12 4 7 10 13 6 8 11 15
 * 实现一个查找函数，返回指定元素的下标。
 * 1  2  8  9
 * 2  4  9 12
 * 4  7 10 13
 * 6  8 11 15
 */
#include <stdio.h>
int find (int arr[], int rows, int cols,
	int key) {
	if (! arr || rows <= 0 || cols <= 0)
		return -1;
	int row = 0, col = cols - 1;
	while (row < rows && col >= 0) {
		int i = row * cols + col;
		if (key < arr[i])
			--col;
		else
		if (arr[i] < key)
			++row;
		else
			return i;
	}
	return -1;
}
int main (void) {
	int arr[] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,
		11,15};
	printf ("数组：");
	size_t i;
	for (i = 0; i < sizeof(arr)/sizeof(arr[0]);
		++i)
		printf ("%d ", arr[i]);
	printf ("\n");
	printf ("查找目标：");
	int key;
	scanf ("%d", &key);
	int res = find (arr, 4, 4, key);
	if (res == -1)
		printf ("没找到！\n");
	else
		printf ("找到了：arr[%d] = %d\n", res,
			arr[res]);
	return 0;
}

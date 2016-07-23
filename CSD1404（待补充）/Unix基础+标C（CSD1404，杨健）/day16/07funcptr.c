/*
	 函数指针形参演示
	 */
#include <stdio.h>
void print(int *p_num) {
		printf("%d ", *p_num);
}
void neg(int *p_num) {
		*p_num = 0 - *p_num;
}
void for_each(int *p_num, int size, void (*p_func)(int*)) {
		int num = 0;
		for (num = 0;num <= size - 1;num++) {
				p_func(p_num + num);
		}
}
int main() {
		int arr[10] = {1, 2, 3, 4, 5, 6,
		                7, 8, 9, 10}, num = 0;
		for_each(arr, 10, print);
		printf("\n");
		for_each(arr, 10, neg);
		for_each(arr, 10, print);
		printf("\n");
		return 0;
}

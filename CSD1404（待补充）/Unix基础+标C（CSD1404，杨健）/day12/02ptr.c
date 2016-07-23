/*
	 指针计算规则演示
	 */
#include <stdio.h>
int main() {
		int arr[10] = {};
		int *p_num = arr, *p_num1 = arr + 5;
		printf("%p %p\n", p_num, p_num + 3);
		printf("%p %p\n", p_num, p_num - 3);
		printf("%d\n", p_num1 - p_num);
		return 0;
}

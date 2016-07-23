/*
	 指针，数组差异演示
	 */
#include <stdio.h>
int main() {
		int arr[3] = {};
		int *p_num = arr;
		printf("%p %p\n", &arr, &p_num);
		printf("%p %p\n", arr, p_num);
		return 0;
}

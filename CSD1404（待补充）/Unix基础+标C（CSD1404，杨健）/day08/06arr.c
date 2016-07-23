/*
	 数组名称演示
	 */
#include <stdio.h>
int main() {
		int arr[2][3] = {};
		int arr1[5] = {};
		printf("sizeof(arr)是%d\n", sizeof(arr));
		printf("sizeof(arr[1])是%d\n", sizeof(arr[1]));
		arr1[3] = 10;
		printf("%d\n", (&arr1)[0][3]);
		return 0;
}



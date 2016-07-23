/*
	 数组演示
	 */
#include <stdio.h>
int main() {
		int arr[5];  //数组声明
		int num = 0;
		arr[2] = 10;
		printf("arr[2]是%d\n", arr[2]);
		printf("arr是%p\n", arr);
		printf("arr + 2是%p\n", arr + 2);
		*(arr + 2) = 20;
		printf("arr[2]是%d\n", arr[2]);
		for (num = 0;num <= 4;num++) {
				arr[num] = num + 1;
		}
		for (num = 4;num >= 0;num--) {
				printf("%d ", arr[num]);
		}
		printf("\n");
		return 0;
}






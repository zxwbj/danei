/*
	 数组做形参演示
	 */
#include <stdio.h>
void print(int arr[], int size) {
		int num = 0;
		printf("sizeof(arr)是%d\n", sizeof(arr));
		for (num = 0;num <= size - 1;num++) {
				printf("%d ", arr[num]);
		}
		printf("\n");
}
int main() {
		int arr[] = {3, 6, 5};
		print(arr, 2);
		print(arr, 3);
		return 0;
}

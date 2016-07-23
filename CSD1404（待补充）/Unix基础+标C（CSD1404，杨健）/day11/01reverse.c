/*
	 递归作业
	 */
#include <stdio.h>
void reverse(int arr[], int start, int end) {
		int tmp = 0;
		if (start >= end) {
				return ;
		}
		tmp = arr[start];
		arr[start] = arr[end];
		arr[end] = tmp;
		reverse(arr, start + 1, end - 1);
}
int main() {
		int arr[] = {1, 2, 3, 4, 5, 6}, num = 0;
		reverse(arr, 0, 5);
		for (num = 0;num <= 5;num++) {
				printf("%d ", arr[num]);
		}
		printf("\n");
		return 0;
}





/*
	 数组形参练习
	 */
#include <stdio.h>
void neg(int arr[], int res[], int size) {
		int num = 0;
		for (num = 0;num <= size - 1;num++) {
				res[num] = 0 - arr[num];
		}
}
int main() {
		int arr[] = {1, 2, 3}, res[3] = {};
		neg(arr, res, 3);
		printf("%d %d %d\n", res[0], res[1], res[2]);
		return 0;
}



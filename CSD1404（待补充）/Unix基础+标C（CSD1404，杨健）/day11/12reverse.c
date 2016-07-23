/*
	 指针形参练习
	 */
#include <stdio.h>
void reverse(int *p_num, int size) {
		int start = 0, end = size - 1;
		while (start < end) {
				/*int tmp = p_num[start];
				p_num[start] = p_num[end];
				p_num[end] = tmp;*/
				int tmp = *(p_num + start);
				*(p_num + start) = *(p_num + end);
				*(p_num + end) = tmp;
				start++;
				end--;
		}
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6}, num = 0;
		reverse(arr, 6);
		for (num = 0;num <= 5;num++) {
				printf("%d ", arr[num]);
		}
		printf("\n");
		return 0;
}

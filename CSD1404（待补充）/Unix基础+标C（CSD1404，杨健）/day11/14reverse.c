/*
	 指针形参练习
	 */
#include <stdio.h>
int *reverse(int *p_num, int size) {
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
		return p_num;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6}, num = 0;
		int *p_num = reverse(arr, 6);
		for (num = 0;num <= 5;num++) {
				printf("%d ", *(p_num + num));
		}
		printf("\n");
		return 0;
}

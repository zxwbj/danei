/*
	 合并数组作业
	 */
#include <stdio.h>
int *merge(const int *p_src, int src_num, int *p_dest, int dest_num) {
		int num = 0;
		for (num = 0;num <= src_num - 1;num++) {
				*(p_dest + dest_num + num) = *(p_src + num);
		}
		return p_dest;
}
int main() {
		int arr[] = {1, 2, 3}, arr1[20] = {10, 11, 12, 13}, num = 0;
		int *p_num = merge(arr, 3, arr1, 4);
		for (num = 0;num <= 6;num++) {
				printf("%d ", *(p_num + num));
		}
		printf("\n");
		return 0;
}





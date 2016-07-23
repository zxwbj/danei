/*
	 颠倒数组顺序练习
	 */
#include <stdio.h>
int main() {
		int arr[] = {1, 2, 3, 4, 5, 6, 7};
		int *p_start = arr, *p_end = arr + 6;
		while (p_start < p_end) {
				int tmp = *p_start;
				*p_start = *p_end;
				*p_end = tmp;
				p_start++;
				p_end--;
		}
		for (p_start = arr;p_start <= arr + 6;p_start++) {
				printf("%d ", *p_start);
		}
		printf("\n");
		return 0;
}

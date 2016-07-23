/*
	 指针和数组演示
	 */
#include <stdio.h>
int main() {
		int arr[] = {1, 2, 3, 4, 5};
		int *p_num = NULL, num = 0;
    /*for (num = 0;num <= 4;num++) {
				printf("%d ", *(p_num + num));
		}*/
		for (p_num = arr;p_num <= arr + 4;p_num++) {
				printf("%d ", *p_num);
		}
		printf("\n");
		return 0;
}

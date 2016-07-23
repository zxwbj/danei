/*
	 递归练习
	 */
#include <stdio.h>
int fei(int num, int arr[]) {
		if (num <= 1) {
				return 1;
		}
		if (!arr[num - 2]) {
				arr[num - 2] = fei(num - 2, arr);
		}
		if (!arr[num - 1]) {
				arr[num - 1] = fei(num - 1, arr);
		}
		return arr[num - 2] + arr[num - 1];
}
int main() {
		int num = 0, arr[50] = {};
		printf("请输入编号：");
		scanf("%d", &num);
		printf("编号为%d的数字是%d\n", num, fei(num, arr));
		return 0;
}




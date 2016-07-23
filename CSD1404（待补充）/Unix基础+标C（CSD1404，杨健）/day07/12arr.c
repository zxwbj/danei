/*
	 数组练习
	 */
#include <stdio.h>
int main() {
		int num = 0, num1 = 0, arr[5];
		printf("请输入一个整数：");
		scanf("%d", &num);
		//拆分每个数位
		for (num1 = 4;num1 >= 0;num1--) {
				arr[num1] = num % 10;
				num /= 10;
		}
		//打印数组中所有存储区内容
		for (num1 = 0;num1 <= 4;num1++) {
				printf("%d ", arr[num1]);
		}
		printf("\n");
		return 0;
}

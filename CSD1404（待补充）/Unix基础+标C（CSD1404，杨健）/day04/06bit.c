/*
	 十进制转二进制练习
	 */
#include <stdio.h>
int main() {
		int num = 0;
		printf("请输入一个整数：");
		scanf("%d", &num);
		printf("%9d\r", num % 2);

		num = num / 2;
		printf("%8d\r", num % 2);

		num = num / 2;
		printf("%7d\r", num % 2);

		num = num / 2;
		printf("%6d\r", num % 2);

		num = num / 2;
		printf("%4d\r", num % 2);

		num = num / 2;
		printf("%3d\r", num % 2);

		num = num / 2;
		printf("%2d\r", num % 2);

		num = num / 2;
		printf("%d\n", num % 2);

		return 0;
}

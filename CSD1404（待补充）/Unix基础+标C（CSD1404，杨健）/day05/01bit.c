/*
	 十进制转二进制作业
	 */
#include <stdio.h>
int main() {
		int num = 0, num1 = 128;
		printf("请输入一个整数：");
		scanf("%d", &num);
		printf("%d", num / num1);

		num %= num1;
		num1 /= 2;
		printf("%d", num / num1);

		num %= num1;
		num1 /= 2;
		printf("%d", num / num1);

		num %= num1;
		num1 /= 2;
		printf("%d ", num / num1);

		num %= num1;
		num1 /= 2;
		printf("%d", num / num1);

		num %= num1;
		num1 /= 2;
		printf("%d", num / num1);

		num %= num1;
		num1 /= 2;
		printf("%d", num / num1);

		num %= num1;
		num1 /= 2;
		printf("%d\n", num / num1);

		return 0;
}

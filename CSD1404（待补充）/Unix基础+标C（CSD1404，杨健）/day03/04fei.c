/*
	 费氏数列练习
	 */
#include <stdio.h>
int main() {
		int num = 0, num1 = 1, num2 = 1;
		num = num1 + num2;
		printf("%d ", num);
		num1 = num2;
		num2 = num;
		num = num1 + num2;
		printf("%d ", num);
		num1 = num2;
		num2 = num;
		num = num1 + num2;
		printf("%d ", num);
		num1 = num2;
		num2 = num;
		num = num1 + num2;
		printf("%d ", num);
		num1 = num2;
		num2 = num;
		num = num1 + num2;
		printf("%d\n", num);
		return 0;
}

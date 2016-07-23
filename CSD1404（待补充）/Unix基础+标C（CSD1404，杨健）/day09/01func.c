/*
	 函数演示
	 */
#include <stdio.h>
int read() {
		int num = 0;
		printf("请输入一个数字：");
		scanf("%d", &num);
		return num;
}
void print() {
		printf("1\n");
}
int mul() {
		int num = 0, num1 = 0;
		printf("请输入两个整数：");
		scanf("%d%d", &num, &num1);
		return num * num1;
}
int main() {
		int num = 0;
		print();
		num = read();
		printf("%d\n", num);
		num = mul();
		printf("乘积结果是%d\n", num);
		return 0;
}



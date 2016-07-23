/*
	 scanf演示
	 */
#include <stdio.h>
int main() {
		int num = 0, num1 = 0;
		printf("请输入两个数字：");
		scanf("a%db%d", &num, &num1);
		printf("num是%d,num1是%d\n", num, num1);
		return 0;
}

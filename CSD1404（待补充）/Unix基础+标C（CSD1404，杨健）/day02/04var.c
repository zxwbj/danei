/*
   变量演示
   */
#include <stdio.h>
int main() {
	int num = 0, num1 = 0; //变量声明语句
	num = 10;  //赋值语句
	num + 4;
	printf("num是%d\n", num);
	num = num;
	printf("num1是%d\n", num1);
	return 0;
}

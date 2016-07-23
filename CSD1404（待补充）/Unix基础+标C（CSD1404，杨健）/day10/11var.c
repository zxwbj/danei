/*
	 变量演示
	 */
#include <stdio.h>
void func() {
		int num;
		printf("num是%d\n", num);
}
void func1() {
		int num = 10;
		int num1 = 12;
		int num2 = num + num1;
}
int num4;
int main() {
		func();
		func1();
		func();
		return 0;
}

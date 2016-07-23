/*
	 静态变量演示
	 */
#include <stdio.h>
void func() {
		static int num = 3;
		printf("%d\n", num);
		num++;
}
void func1() {
		int num = 10;
		int num1 = 12;
		int num2 = num + num1;
}
int main() {
		func();
		func1();
		func();
		return 0;
}

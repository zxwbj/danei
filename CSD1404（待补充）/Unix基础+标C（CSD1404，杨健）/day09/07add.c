/*
	 函数声明演示
	 */
#include <stdio.h>
double add(double, double);
int main() {
		int num = 0;
		num = add(3, 8);
		printf("求和结果是%d\n", num);
		return 0;
}

double add(double num, double num1) {
		return num + num1;
}




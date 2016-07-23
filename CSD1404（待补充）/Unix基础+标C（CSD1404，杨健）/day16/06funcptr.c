/*
	 函数指针练习
	 */
#include <stdio.h>
int add(int x, int y) {
		return x + y;
}
int sub(int x, int y) {
		return x - y;
}
int mul(int x, int y) {
		return x * y;
}
int div(int x, int y) {
		return x / y;
}
int main() {
		int num = 0, num1 = 0;
		char opr = 0;
		int (*p_func)(int, int) = NULL;
		printf("请输入一个表达式：");
		scanf("%d%c%d", &num, &opr, &num1);
    if (opr == '+') {
				p_func = add;
		}
		else if (opr == '-') {
				p_func = sub;
		}
		else if (opr == '*') {
				p_func = mul;
		}
		else {
				p_func = div;
		}
		printf("计算结果是%d\n", p_func(num, num1));
		return 0;
}





/*
	 函数指针演示
	 */
#include <stdio.h>
int add(int x, int y) {
		return x + y;
}
int main() {
    int (*p_func)(int, int) = NULL; //函数指针声明
		p_func = add;
		printf("求和结果是%d\n", p_func(3, 8));
		printf("求和结果是%d\n", (*p_func)(3, 8));
		return 0;
}






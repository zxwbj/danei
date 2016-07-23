/*
	 指针变量演示
	 */
#include <stdio.h>
int main() {
		int num = 0;
		int *p_num = NULL;
		p_num = &num;   //实现指针和普通变量的捆绑
		*p_num = 10;
		printf("num是%d\n", num);
		return 0;
}

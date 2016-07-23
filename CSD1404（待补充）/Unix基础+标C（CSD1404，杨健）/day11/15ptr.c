/*
	 指针类型返回值存储区演示
	 */
#include <stdio.h>
int *read() {
		int num = 0;
		printf("请输入一个整数：");
		scanf("%d", &num);
		return &num;   //不可以把指针类型返回值存储区和局部变量捆绑
}
int main() {
		int *p_num = read();
		printf("num是%d\n", *p_num);
		return 0;
}



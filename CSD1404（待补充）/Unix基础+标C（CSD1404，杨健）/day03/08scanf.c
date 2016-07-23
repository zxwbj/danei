/*
	 scanf演示
	 */
#include <stdio.h>
int main() {
		int num = 0, num1 = 0;
		printf("请输入第一个数字：");
		scanf("%d", &num);
		scanf("%*[^\n]");
		scanf("%*c");
		printf("%d\n", num);
		printf("请输入第二个数字：");
		scanf("%d", &num1);
		printf("%d\n", num1);
		return 0;
}

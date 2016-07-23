/*
	 while练习
	 */
#include <stdio.h>
int main() {
		int num = 0, sum = 0;
		while (sum <= 100) {
				printf("请输入下一个数字：");
				scanf("%d", &num);
				sum += num;
		}
		printf("求和结果是%d\n", sum);
		return 0;
}

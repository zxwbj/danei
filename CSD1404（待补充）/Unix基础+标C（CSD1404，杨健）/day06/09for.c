/*
	 for循环练习
	 */
#include <stdio.h>
int main() {
		int num = 0, result = 0, num1 = 0;
		printf("请输入一个数字：");
		scanf("%d", &num);
		for (num1 = num - 1;num1 >= 1;num1--) {
				if (!(num % num1) && !result) {
				    result = num1;
				}
		}
		printf("结果是%d\n", result);
		return 0;
}




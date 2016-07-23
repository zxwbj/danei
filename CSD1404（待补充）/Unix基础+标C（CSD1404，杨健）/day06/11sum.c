/*
	 求和练习
	 */
#include <stdio.h>
int main() {
		int sum = 0, num = 0, min = 0, max = 0;
		printf("请输入两个数字：");
		scanf("%d%d", &min, &max);
		if (min > max) {
		    int tmp = min;
				min = max;
				max = tmp;
		}
		for (num = min;num <= max;num++) {
				sum += num;
		}
		printf("求和结果是%d\n", sum);
		return 0;
}

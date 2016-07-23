/*
	 逻辑表达式练习
	 */
#include <stdio.h>
int main() {
		int gender = 0, weight = 0, height = 0, result = 0;
		printf("请输入性别，身高和体重：");
		scanf("%d%d%d", &gender, &height, &weight);
		result = (gender && (weight < height - 105)) || (!gender && (weight < height - 110));
		printf("健康情况是%d\n", result);
		return 0;
}

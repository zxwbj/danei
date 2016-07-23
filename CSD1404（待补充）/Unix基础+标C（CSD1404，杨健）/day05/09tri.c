/*
	 三目表达式练习
	 */
#include <stdio.h>
int main() {
		int gender = 0, height = 0, weight = 0, health = 0;
		printf("请输入性别，身高和体重：");
    scanf("%d%d%d", &gender, &height, &weight);
		health = (gender ? weight < height - 105 : weight < height - 110);
		printf("健康状况是%d\n", health);
		return 0;
}




/*
	 健康情况练习
	 */
#include <stdio.h>
int main() {
		int gender = 0, height = 0, weight = 0;
		printf("请输入性别，身高和体重：");
    scanf("%d%d%d", &gender, &height, &weight);
		if (gender) {
				if (weight < height - 105) {
		        printf("健康的男人\n");
				}
				else {
            printf("不健康的男人\n");
				}
		}
		else {
				if (weight < height - 110) {
				    printf("健康的女人\n");
				}
				else {
		        printf("不健康的女人\n");
				}
		}
		return 0;
}



/*
	 指针练习
	 */
#include <stdio.h>
int main() {
		int num = 0, num1 = 0, num2 = 0;
		int *p_max = &num, *p_mid = &num1, *p_min = &num2;
		printf("请输入三个数字：");
		scanf("%d%d%d", p_max, p_mid, p_min);
		if (*p_max < *p_mid) {
				int *p_tmp = p_max;
				p_max = p_mid;
				p_mid = p_tmp;
		}
		if (*p_max < *p_min) {
				int *p_tmp = p_max;
				p_max = p_min;
				p_min = p_tmp;
		}
		if (*p_mid < *p_min) {
				int *p_tmp = p_mid;
				p_mid = p_min;
				p_min = p_tmp;
		}
		printf("%d %d %d\n", *p_max, *p_mid, *p_min);
		return 0;
}





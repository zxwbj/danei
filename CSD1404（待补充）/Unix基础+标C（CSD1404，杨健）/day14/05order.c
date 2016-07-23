/*
	 点菜练习
	 */
#include <stdio.h>
int main() {
		int order = 0;
		printf("请点一个菜：");
		scanf("%d", &order);
#ifdef  ZHAOBENSHAN
		if (order == 1) {
				printf("这个菜没有\n");
		}
		else {
				printf("这个菜真没有\n");
		}
#else
		if (order == 1) {
				printf("这个菜有\n");
		}
		else {
				printf("这个菜没有\n");
		}
#endif
		return 0;
}

/*
	 if分支演示
	 */
#include <stdio.h>
int main() {
		int num = 0;
		printf("请输入一个数字：");
		scanf("%d", &num);
		if (num > 0) {
		    printf("正数\n");
		}
		else if (!num) {
		    printf("零\n");
		}
		else {
		    printf("负数\n");
		}
		return 0;
}




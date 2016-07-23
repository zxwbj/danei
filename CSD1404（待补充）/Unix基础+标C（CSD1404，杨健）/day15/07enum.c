/*
	 枚举练习
	 */
#include <stdio.h>
typedef enum /*gender*/ {
		NAN,
		NV
} gender;
int main() {
    int num = 0;
		printf("请输入一个整数：");
		scanf("%d", &num);
		if (num % 2 == NAN) {
				printf("男\n");
		}
		else {
				printf("女\n");
		}
		return 0;
}




/*
	 switch...case练习
	 */
#include <stdio.h>
int main() {
		int num = 0;
		printf("请输入一个整数：");
    scanf("%d", &num);
		switch (num % 2) {
		case 0:
				printf("女\n");
				break;
		case 1:
				printf("男\n");
				break;
		default:
				printf("无法处理的数字\n");
				break;
		}
		return 0;
}





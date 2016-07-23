/*
	 逻辑操作符演示
	 */
#include <stdio.h>
int main() {
		int num = 10;
		printf("!8是%d\n", !8);
		printf("3 + 5 > 7 + 4是%d\n", 3 + 5 > 7 + 4);
		printf("3 < 7 < 5是%d\n", 3 < 7 < 5);
		printf("3 < 7 && 7 < 5是%d\n", 3 < 7 && 7 < 5);
		0 && ++num;
		printf("num是%d\n", num);
		1 || ++num;
		printf("num是%d\n", num);
		return 0;
}




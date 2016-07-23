/*
	 操作符演示
	 */
#include <stdio.h>
int main() {
		int num = 0;
		char ch = 0;
		//num = (3 + 6, 8 - 2);
		num = 3 + 6, 8 - 2;
		printf("num是%d\n", num);
    num = ch = 200;
		printf("ch是%hhd,num是%d\n", ch, num);
		num = 5;
		//num *= 2;
		num *= 1 + 1;
		printf("num是%d\n", num);
		return 0;
}




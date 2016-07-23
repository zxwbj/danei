/*
	 sizeof关键字演示
	 */
#include <stdio.h>
int main() {
		short snum = 0;
		int num = 0;
		printf("sizeof(short)是%d\n", sizeof(short));
		printf("sizeof(snum)是%d\n", sizeof(snum));
		printf("sizeof(4 + 8)是%d\n", sizeof(4 + 8));
		sizeof(num = 10);
		printf("num是%d\n", num);
		return 0;
}





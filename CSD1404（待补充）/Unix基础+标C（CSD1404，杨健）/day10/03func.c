/*
	 递归练习
	 */
#include <stdio.h>
int yue(int num, int num1) {
		if (!(num % num1)) {
				return num1;
		}
		return yue(num1, num % num1);
}
int main() {
		printf("72和39的最大公约数是%d\n", yue(72, 39));
		return 0;
}




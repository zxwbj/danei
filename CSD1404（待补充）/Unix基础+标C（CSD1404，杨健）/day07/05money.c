/*
	 货币练习
	 */
#include <stdio.h>
int main() {
		int num = 0, num1 = 0;
		for (num = 0;num <= 2;num++) {
				for (num1 = 0;num1 <= (10 - 5 * num) / 2;num1++) {
						printf("5块钱一共有%d张，2块钱一共有%d张，1块钱一共有%d张\n", num, num1, 10 - 5 * num - 2 * num1);
				}
		}
		return 0;
}

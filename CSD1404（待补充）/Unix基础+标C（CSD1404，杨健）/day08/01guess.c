/*
	 猜数游戏作业
	 */
#include <stdio.h>
int main() {
		int guess, num = 0;
		guess = guess >= 0 ? guess : 0 - guess;
		guess %= 100;
		do {
				printf("请猜一个数字：");
        scanf("%d", &num);
				if (num > guess) {
				    printf("猜大了\n");
				}
				else if (num < guess) {
				    printf("猜小了\n");
				}
				else {
				    printf("猜对了\n");
				}
		} while (num != guess);
		return 0;
}

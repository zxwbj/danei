/*
	 砝码练习
	 */
#include <stdio.h>
int main() {
		int num = 0, last = 0;
		for (num = 1;num <= 127;num++) {
        if (num > 2 * last - 1) {
				    printf("%d克 ", num);
						last = num;
				}
		}
		printf("\n");
		return 0;
}

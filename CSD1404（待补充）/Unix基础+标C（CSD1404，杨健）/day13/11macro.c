/*
	 宏练习
	 */
#include <stdio.h>
#define    MAX(x,y)     x > y ? x : y 
#define    NEG(x)       x = 0 - x
int max(int x, int y) {
		if (x > y) {
				return x;
		}
		else {
				return y;
		}
}
void neg(int x) {
		x = 0 - x;
}
int main() {
		int num = 10;
    printf("max(3, 7)是%d\n", max(3, 7));
		printf("MAX(3, 7)是%d\n", MAX(3, 7));
		neg(num);
		printf("num是%d\n", num);
		NEG(num);
		printf("num是%d\n", num);
		return 0;
}




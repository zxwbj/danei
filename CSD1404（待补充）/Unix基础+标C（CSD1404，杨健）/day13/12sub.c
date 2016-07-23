/*
	 宏练习
	 */
#include <stdio.h>
#define    SUB(x,y)         ((x) - (y))
#define    MUL(x,y)         ((x) * (y))
#define    SQUARE(r)        ((r) * (r))
int main() {
		int num = 6;
		printf("SUB(7, 5)是%d\n", SUB(7, 5));
		printf("10 - SUB(5, 3)是%d\n", 10 - SUB(5, 3));
		printf("SUB(10, 5 - 3)是%d\n", SUB(10, 5 - 3));
		printf("平方是%d\n", SQUARE(++num));
		return 0;
}



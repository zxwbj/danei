/*
	 特殊字符演示
	 */
#include <stdio.h>
int main() {
		printf("abc\nde\n");
		printf("abc\rde\n");
		printf("abc\tde\n");
		printf("abcxyz\tde\n");
		printf("abc\new\n");
		printf("abc\\new\n");
		return 0;
}

/*
	 宏操作符演示
	 */
#include <stdio.h>
#define   STR(n)         #n
#define   INT(n)         i_##n
int main() {
		int INT(num) = 0;
    STR(4 - 6 + abc);
		return 0;
}

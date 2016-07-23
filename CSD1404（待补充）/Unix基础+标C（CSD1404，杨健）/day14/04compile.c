/*
	 条件编译
	 */
#include <stdio.h>
int main() {
//#ifdef   ONE
#ifndef ONE
		printf("1\n");
#else
		printf("2\n");
#endif
		return 0;
}

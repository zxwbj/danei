/*
	 输出缓冲区演示
	 */
#include <stdio.h>
int main() {
		printf("abc");
		fflush(stdout);
		while (1);
		return 0;
}

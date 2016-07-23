/*
	 类型转换演示
	 */
#include <stdio.h>
int main() {
    printf("字节个数是%d\n", sizeof(1 ? 1 : 0.9));
		printf("-7 + 3 > 0是%d\n", -7 + 3 > 0);
		printf("-7 + 3u > 0是%d\n", -7 + 3u > 0);
		printf("200是%d\n", (char)200);
		return 0;
}

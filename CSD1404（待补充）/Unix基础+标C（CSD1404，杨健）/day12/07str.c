/*
	 字符串演示
	 */
#include <stdio.h>
int main() {
		//char str[] = "abc";
		char str[] = {'a', 'b', 'c', 0};
		printf("%p\n", "abc");
		printf("%p\n", "abc");
		printf("%p\n", "ab""c");
		printf("sizeof(str)是%d\n", sizeof(str));
		printf("%hhd\n", str[3]);
		return 0;
}

/*
	 字符串函数演示
	 */
#include <stdio.h>
#include <string.h>
int main() {
		char str[20] = "abc";
    printf("有效字符个数是%d\n", strlen("abc"));
		printf("%s\n", strcat(str, "xyz"));
		printf("%s\n", str);
		printf("比较结果是%d\n", strcmp("abc", "abd"));
		printf("%s\n", strcpy(str, "abcdef"));
		printf("%s\n", str);
		return 0;
}





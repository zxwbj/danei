/*
	 字符串练习
	 */
#include <stdio.h>
#include <string.h>
int main() {
		char str[10] = {};
		int num = 0;
		printf("请输入一个字符串：");
		//scanf("%s", str);
		fgets(str, 10, stdin);
		if (strlen(str) == 9 && str[8] != '\n') {
		    scanf("%*[^\n]");
		    scanf("%*c");
		}
		printf("字符串是%s\n", str);
		printf("请输入一个整数：");
		scanf("%d", &num);
		printf("num是%d\n", num);
		return 0;
}

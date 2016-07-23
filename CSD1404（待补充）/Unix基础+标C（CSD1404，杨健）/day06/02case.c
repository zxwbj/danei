/*
	 大小写转换作业
	 */
#include <stdio.h>
int main() {
		char ch = 0;
		printf("请输入一个字符：");
		scanf("%c", &ch);
		ch = (ch >= 'A' && ch <= 'Z' ? ch - 'A' + 'a' : ch - 'a' + 'A');
		printf("转换结果是%c\n", ch);
		return 0;
}

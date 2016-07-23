/*
	 长方形面积作业
	 */
#include <stdio.h>
int main() {
		int length = 0, width = 0;
		printf("请输入长方形的长和宽：");
		scanf("%d%d", &length, &width);
		printf("面积是%d\n", length * width);
		return 0;
}

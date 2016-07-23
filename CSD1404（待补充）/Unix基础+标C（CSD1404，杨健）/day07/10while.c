/*
	 输入缓冲区演示
	 */
#include <stdio.h>
int main() {
		int num = 0;
		while (1) {
		    printf("请输入一个数字：");
		    if (scanf("%d", &num)) {
				   break; 
				}
				scanf("%*[^\n]");
				scanf("%*c");
		}
		scanf("%*[^\n]");
		scanf("%*c");
		printf("num是%d\n", num);
		printf("请输入一个数字：");
		scanf("%d", &num);
		printf("num是%d\n", num);
		return 0;
}

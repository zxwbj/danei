/*
	 动态分配内存练习
	 */
#include <stdio.h>
#include <stdlib.h>
int main() {
		int num = 0;
    int *p_num = (int*)malloc(3 * sizeof(int));
		if (p_num) {
				for (num = 0;num <= 2;num++) {
						printf("请输入一个整数：");
						scanf("%d", p_num + num);
				}
				for (num = 2;num >= 0;num--) {
						printf("%d ", *(p_num + num));
				}
				printf("\n");
				free(p_num);
				p_num = NULL;
		}
		return 0;
}




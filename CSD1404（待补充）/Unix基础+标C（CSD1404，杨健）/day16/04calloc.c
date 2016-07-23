/*
	 calloc演示
	 */
#include <stdio.h>
#include <stdlib.h>
int main() {
		int *p_num = (int*)calloc(3, sizeof(int));
		int num = 0;
		if (p_num) {
				for (num = 0;num <= 2;num++) {
						printf("%d ", *(p_num + num));
				}
				printf("\n");
				free(p_num);
				p_num = NULL;
		}
		return 0;
}

/*
	 动态分配内存框架
	 */
#include <stdio.h>
#include <stdlib.h>
int main() {
		int *p_num = (int*)malloc(3 * sizeof(int));
		if (p_num) {
				//
				free(p_num);
				p_num = NULL;
		}
		return 0;
}




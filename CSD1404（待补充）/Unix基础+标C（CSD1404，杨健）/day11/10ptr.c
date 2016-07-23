/*
	 指针类型演示
	 */
#include <stdio.h>
int main() {
		int num = 300;
		char *p_ch = &num;
		int *p_num = &num;
		printf("%d %d\n", sizeof(p_ch), sizeof(p_num));
		printf("%d %d %d\n", *p_ch, *p_num, *(char*)p_num);
		return 0;
}




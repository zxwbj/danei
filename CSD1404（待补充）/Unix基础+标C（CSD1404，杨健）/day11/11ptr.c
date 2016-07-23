/*
	 void*指针演示
	 */
#include <stdio.h>
int main() {
		int num = 10;
		float f_num = 3.7f;
		char ch = 't';
		void *p_num = NULL;
		p_num = &num;
		printf("%d\n", *(int*)p_num);
		p_num = &f_num;
		printf("%g\n", *(float*)p_num);
		p_num = &ch;
		printf("%c\n", *(char*)p_num);
		return 0;
}

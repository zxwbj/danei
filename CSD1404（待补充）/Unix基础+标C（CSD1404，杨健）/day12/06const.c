/*
	 const指针演示
	 */
#include <stdio.h>
int main() {
		int num = 10;
		const int *p_num = &num;
		int * const p_num1 = &num;
		//*p_num = 0;    错误
		p_num = NULL;
		*p_num1 = 0;
		//p_num1 = NULL;   错误
		return 0;
}

/*
	 联合演示
	 */
#include <stdio.h>
typedef union /*un*/ {
		int num;
		char ch[2];
} un;
int main() {
		un un1 = {};
    printf("sizeof(un)是%d\n", sizeof(un));
		printf("&(un1.num)是%p,un1.ch是%p\n", &(un1.num), un1.ch);
		return 0;
}


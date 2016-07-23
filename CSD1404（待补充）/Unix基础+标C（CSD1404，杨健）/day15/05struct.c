/*
	 数据对齐和补齐
	 */
#include <stdio.h>
typedef struct {
		char ch;
		int num;
} stru;
typedef struct {
		char ch;
		short snum;
		char ch1;
} stru1;
int main() {
		printf("sizeof(stru)是%d\n", sizeof(stru));
		printf("sizeof(stru1)是%d\n", sizeof(stru1));
		return 0;
}

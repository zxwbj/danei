/*
	 打印字符二进制补码作业
	 */
#include <stdio.h>
int main() {
		char ch = 0;
		unsigned char uch = 128;
		int shift = 7;
		printf("请输入一个字符：");
    scanf("%c", &ch);
		//ch = -56;
		printf("%hhu", (ch & uch) >> shift);

		uch >>= 1;
		shift--;
		printf("%hhu", (ch & uch) >> shift);

		uch >>= 1;
		shift--;
		printf("%hhu", (ch & uch) >> shift);

		uch >>= 1;
		shift--;
		printf("%hhu ", (ch & uch) >> shift);

		uch >>= 1;
		shift--;
		printf("%hhu", (ch & uch) >> shift);

		uch >>= 1;
		shift--;
		printf("%hhu", (ch & uch) >> shift);

		uch >>= 1;
		shift--;
		printf("%hhu", (ch & uch) >> shift);

		uch >>= 1;
		shift--;
		printf("%hhu\n", (ch & uch) >> shift);

		return 0;
}






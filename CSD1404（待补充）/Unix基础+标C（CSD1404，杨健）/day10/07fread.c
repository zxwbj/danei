/*
	 fread演示
	 */
#include <stdio.h>
int main() {
		char ch[5] = {};
		int size = 0;
		FILE *p_file = fopen("a.txt", "rb");
		if (p_file) {
        size = fread(ch, sizeof(char), 5, p_file);
				printf("一共拷贝%d个字节\n", size);
				printf("%c%c%c%c%c\n", ch[0], ch[1], ch[2], ch[3], ch[4]);
				fclose(p_file);
				p_file = NULL;
		}
		return 0;
}

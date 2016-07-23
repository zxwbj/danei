/*
	 fwrite函数演示
	 */
#include <stdio.h>
int main() {
		char ch[] = {'a', 'b', 'c', 'd', 'e'};
		int size = 0;
		FILE *p_file = fopen("a.txt", "wb");
		if (p_file) {
				size = fwrite(ch, sizeof(char), 5, p_file);
				printf("一共拷贝了%d个字节\n", size);
				fclose(p_file);
				p_file = NULL;
		}
		return 0;
}

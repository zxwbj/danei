/*
	 位置指针演示
	 */
#include <stdio.h>
int main() {
		char ch = 0;
		FILE *p_file = fopen("b.txt", "rb");
		if (p_file) {
				//rewind(p_file);
				fseek(p_file, 1, SEEK_SET);
				printf("位置指针是%ld\n", ftell(p_file));
				fread(&ch, sizeof(char), 1, p_file);
				printf("%c\n", ch);
				fseek(p_file, 2, SEEK_CUR);
				//rewind(p_file);
				printf("位置指针是%ld\n", ftell(p_file));
				fread(&ch, sizeof(char), 1, p_file);
				printf("%c\n", ch);
				fseek(p_file, -6, SEEK_END);
				//rewind(p_file);
				printf("位置指针是%ld\n", ftell(p_file));
				fread(&ch, sizeof(char), 1, p_file);
				printf("%c\n", ch);
				fclose(p_file);
				p_file = NULL;
		}
		return 0;
}

/*
	 字符串拷贝作业
	 */
#include <stdio.h>
#include <stdlib.h>
char *mystrcpy(const char *p_str) {
		const char *p_src = p_str;
		char *p_dest = NULL;
		while (*p_src) {
				p_src++;
		}
		p_dest = (char*)malloc(p_src - p_str + 1);
		if (p_dest) {
				p_src = p_str;
				char *p_tmp = p_dest;
				while (*p_src) {
            *p_tmp = *p_src;
						p_src++;
						p_tmp++;
				}
				*p_tmp = 0;
		}
		return p_dest;
}
int main() {
		char *p_str = mystrcpy("abcxyz");
		if (p_str) {
				printf("%s\n", p_str);
				free(p_str);
				p_str = NULL;
		}
		return 0;
}







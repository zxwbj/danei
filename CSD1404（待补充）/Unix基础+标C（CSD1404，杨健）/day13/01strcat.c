/*
	 字符串合并练习
	 */
#include <stdio.h>
char *mystrcat(char *p_dest, const char *p_src) {
		char *p_dest1 = p_dest;
		const char *p_src1 = p_src;
		while (*p_dest1) {
				p_dest1++;
		}
    while (*p_src1) {
				*p_dest1 = *p_src1;
				p_src1++;
				p_dest1++;
		}
		*p_dest1 = 0;
		return p_dest;
}
int main() {
    char str[20] = "abc";
		printf("%s\n", mystrcat(str, "xyz"));
		printf("%s\n", str);
		return 0;
}

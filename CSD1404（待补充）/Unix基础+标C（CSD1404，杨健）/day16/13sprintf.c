/*
	 sprintf演示
	 */
#include <stdio.h>
int main() {
		int num = 67;
		char ch = 'y';
		float fnum = 4.21f;
		char str[20] = {};
		sprintf(str, "%c %d %g", ch, num, fnum);
		printf("%s\n", str);
		return 0;
}





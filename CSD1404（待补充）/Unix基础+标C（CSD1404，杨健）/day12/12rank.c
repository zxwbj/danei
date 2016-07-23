/*
	 字符串拆分练习
	 */
#include <stdio.h>
int main() {
		char rank[] = "15,26,39,48,100";
		char ranks[5][4] = {};
		int row = 0, col = 0;
		char *p_ch = rank;
		while (*p_ch != '\0') {
				if (*p_ch != ',') {
				    ranks[row][col] = *p_ch;
				}
				if (*p_ch != ',') {
				    col++;
				}
				else {
						row++;
						col = 0;
				}
				p_ch++;
		}
		for (row = 0;row <= 4;row++) {
				printf("%s\n", ranks[row]);
		}
    return 0;
}



/*
	 拆分成绩作业
	 */
#include <stdio.h>
int main() {
		char rank[] = "15,27,31,95,100";
		char *ranks[5] = {};
		char *p_tmp = rank;
		int pos = 1;
		ranks[0] = rank;
		while (*p_tmp) {
				if (*p_tmp == ',') {
						*p_tmp = 0;
						ranks[pos] = p_tmp + 1;
						pos++;
				}
				p_tmp++;
		}
		for (pos = 0;pos <= 4;pos++) {
				printf("%s\n", ranks[pos]);
		}
		return 0;
}

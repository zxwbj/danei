/*
	 sscanf演示
	 */
#include <stdio.h>
int main() {
		int num = 0;
		char ch = 0;
		float fnum = 0.0f;
		sscanf("45 a 4.73", "%d %c %g", &num, &ch, &fnum);
		printf("%c %g %d\n", ch, fnum, num);
		return 0;
}

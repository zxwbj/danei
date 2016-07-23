/*
	 枚举演示
	 */
#include <stdio.h>
typedef enum /*season*/ {
		SPR,
		SUM = 5,
		AUT,
		WIN
} season;
int main() {
		//enum season s;
		season s;
		printf("SPR是%d\n", SPR);
		printf("AUT是%d\n", AUT);
		return 0;
}




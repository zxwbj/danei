/*
	多个字符串演示
	 */
#include <stdio.h>
int main() {
		/*char countries[][10] = {"China", "Russia",
				"England", "America", "France"};*/
		char *countries[] = {"China", "Russia", 
				"England", "America", "France"};
		int num = 0;
		for (num = 0;num <= 4;num++) {
				printf("%s\n", countries[num]);
		}
		return 0;
}

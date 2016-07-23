/*
	 二级指针演示
	 */
#include <stdio.h>
int main() {
		char *countries[] = {"China", "Russia", 
				"England", "America", "France"};
		char **pp_countries = countries;  //把二级指针和指针数组捆绑
		int num = 0;
		for (num = 0;num <= 4;num++) {
				//printf("%s\n", countries[num]);
				//printf("%s\n", pp_countries[num]);
				printf("%s\n", *(pp_countries + num));
		}
		return 0;
}

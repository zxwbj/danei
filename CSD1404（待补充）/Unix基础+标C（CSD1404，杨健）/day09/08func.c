/*
	 递归函数演示
	 */
#include <stdio.h>
void print(int times) {
		if (!times) {
				return ;
		}
		printf("1\n");
		print(times - 1);
}
int main() {
		print(3);
		return 0;
}

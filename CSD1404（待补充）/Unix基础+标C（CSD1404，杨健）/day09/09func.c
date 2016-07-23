/*
	 递归函数练习
	 */
#include <stdio.h>
/*void print(int num) {
		if (num == 10) {
				return ;
		}
    printf("%d ", num);
		print(num + 1);
}*/
void print1(int num) {
		if (num == 3) {
				return ;
		}
		print1(num - 1);
		printf("%d ", num);
}
int main() {
    //print(4);
		print1(9);
		printf("\n");
		return 0;
}

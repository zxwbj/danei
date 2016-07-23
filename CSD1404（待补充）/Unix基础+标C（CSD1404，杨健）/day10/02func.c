/*
	 递归作业
	 */
#include <stdio.h>
int sum(int num) {
		if (num == 1) {
				return 1;
		}
		return num + sum(num - 1);
}
int main() {
		printf("求和结果是%d\n", sum(10));
		return 0;
}




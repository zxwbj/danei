/*
	 多文件编程练习
	 */
#include <stdio.h>
#include "08print.h"
int main() {
    int num = 0;
		for (num = 1;num <= 5;num++) {
				print(num, 10 - num);
		}
		return 0;
}

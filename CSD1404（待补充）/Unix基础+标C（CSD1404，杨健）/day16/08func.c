/*
	 函数演示
	 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
		int num = atoi("123");
		double dnum = atof("34.67");
		printf("num是%d\n", num);
		printf("dnum是%lg\n", dnum);
		dnum = sqrt(20.56);
		printf("平方根是%lg\n", dnum);
		dnum = pow(2.5, 6.7);
		printf("计算结果是%lg\n", dnum);
		return 0;
}





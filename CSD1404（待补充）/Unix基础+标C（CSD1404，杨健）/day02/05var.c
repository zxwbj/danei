/*
   变量演示
   */
#include <stdio.h>
int main() {
	int price = 8/*单价*/, weight = 3/*重量*/; 
	price * weight;
	printf("%d X %d = %d\n", price, weight, price * weight);
	return 0;
}

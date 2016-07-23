/*
	 参数演示
	 */
#include <stdio.h>
void print(int num) {
    printf("%d\n", num);
}
int mul(int num, int num1) {
		return num * num1;
}
int max(int num, int num1) {
		return num > num1 ? num : num1;
}
int main() {
		int num = 0, num1 = 0;
    print(4);
		print(2 + 3);
    printf("请输入两个整数：");
		scanf("%d%d", &num, &num1);
		num = mul(num, num1);
		printf("乘积是%d\n", num);
		printf("最大数字是%d\n", max(max(4, 7), 5));
		return 0;
}




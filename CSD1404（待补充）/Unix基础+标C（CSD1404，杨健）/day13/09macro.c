/*
	 宏演示
	 */
#include <stdio.h>
#define    PI               3.14f
#define    CIRCLE(r)        2 * PI * r
#define    AREA(r)          PI * r * r
int main() {
		const float pi = 3.14f;
		int radius = 0;
		printf("请输入圆的半径：");
		scanf("%d", &radius);
		printf("周长是%g\n", CIRCLE(radius));
		printf("面积是%g\n", AREA(radius));
		printf("周长是%g\n", 2 * pi * radius);
		return 0;
}

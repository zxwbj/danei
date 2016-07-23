/*
    计算月份天数作业
	 */
#include <stdio.h>
int main() {
		int year = 0, month = 0 ;
		printf("请输入年份和月份数字：");
		scanf("%d%d", &year, &month);
		if (month == 1 || month == 3 || month == 5
				|| month == 7 || month == 8 
				|| month == 10 || month == 12) {
		    printf("一共有31天\n");
		}
		else if (month == 4 || month == 6 || month == 9
				|| month == 11) {
		    printf("一共有30天\n");
		}
		else if (month == 2) {
				if ((!(year % 4) && (year % 100)) || !(year % 400)) {
		        printf("一共有29天\n");
				}
				else {
				    printf("一共有28天\n");
				}
		}
		return 0;
}

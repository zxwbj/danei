/*
	 数位统计作业
	 */
#include <stdio.h>
int main() {
		int arr[6] = {}, num = 0, num1 = 0;
		int res[10] = {};
		printf("请输入一个整数：");
		scanf("%d", &num);
		//拆分所有数位
		for (num1 = 5;num1 >= 0;num1--) {
				arr[num1] = num % 10;
				num /= 10;
				//如果拆分结束就立刻结束循环
				if (!num) {
				    break;
				}
		}
		//统计出现次数
    for (num = num1;num <= 5;num++) {
				res[arr[num]]++;
		}
		//打印统计结果
		for (num = 0;num <= 9;num++) {
				printf("数字%d出现次数是%d\n", num, res[num]);
		}
		return 0;
}






/*
	 fwrite练习
	 */
#include <stdio.h>
int main() {
		int arr[3] = {}, num = 0, size = 0;
		FILE *p_file = fopen("a.bin", "wb");
		if (p_file) {
        for (num = 0;num <= 2;num++) {
						printf("请输入一个整数：");
						scanf("%d", arr + num);
				}
				size = fwrite(arr, sizeof(int), 3, p_file);
				printf("一共拷贝了%d个整数\n", size);
				fclose(p_file);
				p_file = NULL;
		}
		return 0;
}

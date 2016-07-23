/*
	 fread练习
	 */
#include <stdio.h>
int main() {
		int arr[3] = {}, size = 0;
		FILE *p_file = fopen("a.bin", "rb");
		if (p_file) {
				size = fread(arr, sizeof(int), 3, p_file);
				printf("一共拷贝%d个整数\n", size);
				printf("%d %d %d\n", arr[0], arr[1], arr[2]);
				fclose(p_file);
				p_file = NULL;
		}
		return 0;
}

/*
	 二维数组演示
	 */
#include <stdio.h>
int main() {
		//int arr[2][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};   //二维数组声明
		int arr[][5] = {{1, 2, 3, 4, 5}, 
				            {6, 7, 8, 9, 10}};
		int row = 0, col = 0;
		/*arr[1][2] = 10;
		for (row = 0;row <= 1;row++) {
				for (col = 0;col <= 4;col++) {
						arr[row][col] = 5 * row + col + 1;
				}
		}*/
		for (row = 0;row <= 1;row++) {
				for (col = 0;col <= 4;col++) {
						printf("%d ", arr[row][col]);
				}
				printf("\n");
		}
		return 0;
}





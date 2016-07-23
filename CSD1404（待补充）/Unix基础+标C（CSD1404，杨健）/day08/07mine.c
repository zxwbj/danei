/*
	 布雷练习
	 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
		char map[10][10] = {};
		int row = 0, col = 0, mines = 0;
		srand(time(0));
		//初始化所有存储区
		for (row = 0;row <= 9;row++) {
				for (col = 0;col <= 9;col++) {
						map[row][col] = '*';
				}
		}
		//放地雷
		do {
        row = rand() % 10;
				col = rand() % 10;
				if (map[row][col] != 'O') {
				    map[row][col] = 'O';
						mines++;
				}
		} while (mines < 10);
		//打印地图
		for (row = 0;row <= 9;row++) {
				for (col = 0;col <= 9;col++) {
						printf("%c", map[row][col]);
				}
				printf("\n");
		}
		return 0;
}




/*
	 打地鼠游戏
	 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
		int times = 0, mouserow = 0, mousecol = 0,posrow = 0, poscol = 0, hits = 0, missed = 0;
		int row = 0, col = 0;
		srand(time(0));
		printf("请输入次数：");
		scanf("%d", &times);
		for (;times >= 1;times--) {
				printf("请输入锤子的位置：");
				scanf("%d%d", &posrow, &poscol);
				mouserow = rand() % 3 + 1;
				mousecol = rand() % 3 + 1;
				for (row = 1;row <= 3;row++) {
						for (col = 1;col <= 3;col++) {
								if (row == posrow && col == poscol) {
								    printf("O");
								}
								else if ((mouserow != posrow || mousecol != poscol) && (row == mouserow && col == mousecol)) {
								    printf("X");
								}
								else {
								    printf("*");
								}
						}
						printf("\n");
				}
				if (mouserow == posrow && mousecol == poscol) {
				    printf("打中了\n");
						hits++;
				}
				else {
				    printf("没打中\n");
						missed++;
				}
		    printf("打中%d次，错过%d次\n", hits, missed);
		}
		return 0;
}





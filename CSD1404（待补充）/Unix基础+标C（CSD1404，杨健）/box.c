/*
   推葙子练习
   */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int arr[10][10] = {};   //记录地图信息
	int direction = 0/*方向*/, stepx = 0/*水平移动方式*/, stepy = 0/*垂直移动方式*/;
	int posx = 0 /*人员水平位置*/, posy = 0 /*人员垂直位置*/;
	int row = 0, col = 0;
	srand(time(0));
	//放置人员和葙子
	arr[rand() % 8 + 1][rand() % 8 + 1] = 1;
	while (1) {
        posx = rand() % 10;
		posy = rand() % 10;
		if (arr[posy][posx] != 1) {
			break;
		}
	}
	arr[posy][posx] = 2;
	//显示棋盘
	for (row = 0;row <= 9;row++) {
		for (col = 0;col <= 9;col++) {
			if (arr[row][col] == 0) {
				printf("*");
			}
			else if (arr[row][col] == 1) {
				printf("X");
			}
			else {
				printf("O");
			}
		}
		printf("\n");
	}
	//每次循环获得一个方向，不一定会真正移动
	while (arr[0][9] != 1) {
		//获得移动方向
	    printf("请输入移动方向，0上，1左，2下，3右");
	    scanf("%d", &direction);
		//使用水平，垂直方向各自的移动方式
		//表示移动方向
		if (direction == 0) {
			stepx = 0;
			stepy = -1;
		}
		else if (direction == 1) {
			stepx = -1;
			stepy = 0;
		}
		else if (direction == 2) {
			stepx = 0;
			stepy = 1;
		}
		else {
			stepx = 1;
			stepy = 0;
		}
        //移动人员位置
		if ((0 <= posx + stepx) && (posx + stepx <= 9) && (0 <= posy + stepy) && (posy + stepy <= 9)) { 
			if (arr[posy + stepy][posx + stepx] == 1) {
				//移动后的位置是葙子
                if (0 <= posx + 2 * stepx && 
					posx + 2 * stepx <= 9 && 
					0 <= posy + 2 * stepy && 
					posy + 2 * stepy <= 9) {
					//葙子另一边还在地图上
					arr[posy + 2 * stepy][posx + 2 * stepx] = 1;   //移动葙子
					arr[posy + stepy][posx + stepx] = 2;    //移动人
					arr[posy][posx] = 0;  //原位置变成空
					posx += stepx; //修改人员水平位置
					posy += stepy; //修改人员垂直位置
	                //显示棋盘
	                for (row = 0;row <= 9;row++) {
		                for (col = 0;col <= 9;col++) {
			                if (arr[row][col] == 0) {
				                printf("*");
		 	                }
			                else if (arr[row][col] == 1) {
				                printf("X");
			                }
			                else {
				                printf("O");
			                }
		                }
		                printf("\n");
	                }
				}
			}
			else {
				//移动后的位置是空
				arr[posy][posx] = 0;
				posx += stepx;
				posy += stepy;
				arr[posy][posx] = 2;
	            //显示棋盘
	            for (row = 0;row <= 9;row++) {
		            for (col = 0;col <= 9;col++) {
			            if (arr[row][col] == 0) {
				            printf("*");
			            }
			            else if (arr[row][col] == 1) {
				            printf("X");
			            }
			            else {
				            printf("O");
			            }
		            }
		            printf("\n");
	            }
			}
		}
	}
	printf("你赢了\n");
	return 0;
	getchar();
}








/*
	 结构体练习
	 */
#include <stdio.h>
typedef struct pt {
		int x, y;
} pt;
typedef struct rect {
		pt pt1, pt2;
} rect;
int main() {
    pt pt1 = {3};
		pt pt2 = pt1;
		pt *p_pt = &pt1;
		//rect r = {{2, 7}, {9, 14}};
		rect r = {2, 7, 9, 14};
		printf("(%d, %d)\n", pt1.x, pt1.y);
		printf("(%d, %d)\n", pt2.x, pt2.y);
		printf("(%d, %d)\n", (*p_pt).x, (*p_pt).y);
		printf("(%d, %d)\n", p_pt->x, p_pt->y);
		printf("((%d, %d), (%d, %d))\n", r.pt1.x, r.pt1.y, r.pt2.x, r.pt2.y);
		return 0;
}




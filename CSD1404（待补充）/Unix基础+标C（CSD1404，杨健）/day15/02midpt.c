/*
	 结构体作业
	 */
#include <stdio.h>
typedef struct {
		int x, y;
} pt;
pt *midpt(const pt *p_pt1, const pt *p_pt2, pt *p_mid) {
    p_mid->x = (p_pt1->x + p_pt2->x) / 2;
		p_mid->y = (p_pt1->y + p_pt2->y) / 2;
		return p_mid;
}
/*pt midpt(pt pt1, pt pt2) {
		pt mid = {};
		mid.x = (pt1.x + pt2.x) / 2;
    mid.y = (pt1.y + pt2.y) / 2;
		return mid;
}*/
int main() {
		pt pt1 = {}, pt2 = {}, mid = {}, *p_mid = NULL;
		printf("请输入起点位置：");
		scanf("%d%d", &pt1.x, &pt1.y);
		printf("请输入终点位置：");
		scanf("%d%d", &pt2.x, &pt2.y);
    /*mid.x = (pt1.x + pt2.x) / 2;
		mid.y = (pt1.y + pt2.y) / 2;*/
		//mid = midpt(pt1, pt2);
		p_mid = midpt(&pt1, &pt2, &mid);
		printf("中间点位置是(%d, %d)\n", mid.x, mid.y);
		printf("中间点位置是(%d, %d)\n", p_mid->x, p_mid->y);
		return 0;
}







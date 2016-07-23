/*
	 结构体练习
	 */
#include <stdio.h>
typedef struct {
		int x, y;
} pt;
typedef struct {
		pt pt1, pt2;
} rect;
pt *read(pt *p_pt) {
		printf("请输入点的位置：");
		scanf("%d%d", &(p_pt->x), &(p_pt->y));
		return p_pt;
}
int calcu(const rect *p_rect) {
		int area = (p_rect->pt1.x - p_rect->pt2.x) * (p_rect->pt1.y - p_rect->pt2.y);
		return area > 0 ? area : 0 - area;
}
int main() {
    rect r = {};
		int area = 0;
		/*printf("请输入第一个点的位置：");
		scanf("%d%d", &r.pt1.x, &r.pt1.y);
		printf("请输入第二个点的位置：");
		scanf("%d%d", &r.pt2.x, &r.pt2.y);*/
		read(&(r.pt1));
		read(&(r.pt2));
    /*area = (r.pt1.x - r.pt2.x) * (r.pt1.y - r.pt2.y);
		area = area > 0 ? area : 0 - area;
		printf("面积是%d\n", area);*/
		printf("面积是%d\n", calcu(&r));
		return 0;
}




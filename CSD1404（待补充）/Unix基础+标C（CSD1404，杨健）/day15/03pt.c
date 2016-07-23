/*
	 结构体练习
	 */
#include <stdio.h>
typedef struct {
		int x, y;
} pt;
pt *read(pt *p_pt) {
		printf("请输入位置信息：");
		scanf("%d%d", &(p_pt->x), &(p_pt->y));
		return p_pt;
}
void print(const pt *p_pt) {
		printf("(%d, %d)\n", p_pt->x, p_pt->y);
}
int main() {
    pt pt1 = {}, *p_pt = NULL;
		p_pt = read(&pt1);
		print(&pt1);
		print(p_pt);
		return 0;
}






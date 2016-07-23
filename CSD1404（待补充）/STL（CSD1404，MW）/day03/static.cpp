#include <iostream>
using namespace std;
// 圆形类
class Circle {
public:
	// 绘制
	void draw (void) const {
		cout << "画圆形" << endl;
	}
};
// 矩形类
class Rectangle {
public:
	// 绘制
	void draw (void) const {
		cout << "画矩形" << endl;
	}
};
// 绘制任意形状————多态函数————抽象
template<typename Shape>
void drawShape (Shape const& shape) {
	shape.draw ();
}
int main (void) {
	Circle c1, c2;
	Rectangle r1, r2;
	drawShape (c1);
	drawShape (r1);
	drawShape (c2);
	drawShape (r2);
	return 0;
}

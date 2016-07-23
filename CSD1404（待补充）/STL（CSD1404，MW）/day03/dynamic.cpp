#include <iostream>
using namespace std;
// 形状类
class Shape {
public:
	// 绘制
	virtual void draw (void) const = 0;
};
// 圆形类
class Circle : public Shape {
public:
	// 绘制
	void draw (void) const {
		cout << "画圆形" << endl;
	}
};
// 矩形类
class Rectangle : public Shape {
public:
	// 绘制
	void draw (void) const {
		cout << "画矩形" << endl;
	}
};
// 绘制任意形状————多态函数————抽象
void drawShape (Shape const& shape) {
	shape.draw ();
}
void drawShapes (Shape const* const* shapes) {
	for (size_t i = 0; shapes[i]; ++i)
		shapes[i]->draw ();
}
int main (void) {
	Circle c1, c2;
	Rectangle r1, r2;
	drawShape (c1);
	drawShape (r1);
	drawShape (c2);
	drawShape (r2);
	cout << "------" << endl;
	Shape* shapes[] = {&c1, &r1, &c2, &r2, 0};
	drawShapes (shapes);
	return 0;
}

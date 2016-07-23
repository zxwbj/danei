#include <iostream>
#include <typeinfo>
using namespace std;
template<typename T>
void foo (T const& x, T const& y) {
	cout << typeid (x).name () << ' '
		<< typeid (y).name () << endl;
}
template<typename T>
void bar (void) {
	T x, y;
	cout << typeid (x).name () << ' '
		<< typeid (y).name () << endl;
}
template<typename R, typename T>
R hum (T const& x) {
	R y;
	cout << typeid (x).name () << ' '
		<< typeid (y).name () << endl;
	return y;
}
int main (void) {
	int a, b;
	foo (a, b);
	double c, d;
	foo (c, d);
	char e[256], f[256];
	foo (e, f);
	string g, h;
	foo (g, h);
	// 隐式推断不允许隐式类型转换
	/*
	foo (a, c);
	*/
	foo<int> (a, c);
	foo (a, (int)c);
	// 没有参数没法隐式推断
	/*
	bar ();
	*/
	bar<double> ();
	int i;
	double j;
	// 返回类型不参与隐式推断
	/*
	i = hum (j);
	*/
	i = hum<int, double> (j);
	i = hum<int> (j);
	return 0;
}

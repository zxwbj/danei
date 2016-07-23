#include <cstdlib>
#include <iostream>
using namespace std;
template<typename T>
class Base {
public:
	class Nested {};
	void foo (void) {}
	int m_x;
	void exit (int status) {
		cout << "再见！" << endl;
	}
};
template<typename T>
class Derived : public Base<T> {
public:
	void bar (void) {
		// 在子模板中访问基模板的成员类型、成员函
		// 数和成员变量，需要使用作用域限定符，否
		// 则编译器只会在子模板中寻找所引用符号的
		// 定义，产生编译错误
		typename Base<T>::Nested nested;
		Base<T>::foo ();
		Base<T>::m_x++;
		// 也可以通过显式的this指针访问
		// 基模板的成员函数和成员变量
		this->foo ();
		this->m_x++;
		this->exit (0);
	}
};
int main (void) {
	Derived<int> d;
	d.bar ();
	return 0;
}

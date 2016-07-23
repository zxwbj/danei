#include <cstring>
#include <iostream>
#include <typeinfo>
using namespace std;
// 两个任意类型值的最大值
template<typename T>
T const& max (T const& x, T const& y) {
	cout << "<1" << typeid (x).name () << '>'
		<< flush;
	return x < y ? y : x;
}
// 两个任意类型指针所指向目标的最大值
template<typename T>
T* const& max (T* const& x, T* const& y) {
	cout << "<2" << typeid (x).name () << '>'
		<< flush;
	return *x < *y ? y : x;
}
/*
// 两个C风格字符串的最大值
char const* const& max (char const* const& x,
	char const* const& y) {
	cout << "<3" << typeid (x).name () << '>'
		<< flush;
	return strcmp (x, y) < 0 ? y : x;
}
*/
// 三个任意类型值的最大值
template<typename T>
T const& max (T const& x, T const& y,
	T const& z) {
	cout << "<4" << typeid (x).name () << '>'
		<< flush;
	return ::max (::max (x, y), z);
}
// 两个C风格字符串的最大值
char const* const& max (char const* const& x,
	char const* const& y) {
	cout << "<3" << typeid (x).name () << '>'
		<< flush;
	return strcmp (x, y) < 0 ? y : x;
}
int main (void) {
	char const* x = "ABC";
	char const* y = "AB";
	char const* z = "A";
	// 编译器优先选择普通函数
	// ————最小风险原则
	cout << ::max (x, y) << endl; // 3
	// 除非函数模板能够产生具有更好匹配性的函数
	// ————类型安全原则
	cout << ::max (100, 200) << endl; // 1
	// 在参数传递过程中如果需要隐式类型转换，
	// 编译器将选择普通函数
	cout << ::max (x, (char*)y) << endl; // 3
	// 通过空模板参数列表告诉编译器使用函数模
	// 板，针对指针的版本显然比任意类型版本具
	// 有更好的匹配性————最佳匹配原则
	cout << ::max<> (x, y) << endl; // 2
	// 显式指定的模板参数必须在所选择的重载版
	// 本中与调用参数的类型保持一致
	cout << ::max<char const*> (x, y) << endl;
	// 1
	// 在函数模板的实例化函数中，编译器仍然优
	// 先选择普通函数
	cout << ::max (x, y, z) << endl; // 4-3
	// 除非该普通函数在编译函数模板时不可见
	// 4-2
	return 0;
}

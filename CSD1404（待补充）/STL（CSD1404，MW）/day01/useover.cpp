#include <cstring>
#include <iostream>
using namespace std;
// 在重载函数模板的时候，应该尽可能地把改变限
// 制在模版参数的个数或模版参数的具体类型上，
// 而对于该参数的引用属性最好保持不变，避免导
// 致非预期的后果。
template<typename T>
T const& max (T const& x, T const& y) {
	return x < y ? y : x;
}
// 正确的写法
char const* const& max (char const* const& x,
	char const* const& y) {
	return strcmp (x, y) < 0 ? y : x;
}
/* 错误的写法
char const* max (char const* x,
	char const* y) {
	return strcmp (x, y) < 0 ? y : x;
}
*/
template<typename T>
T const& max (T const& x, T const& y,
	T const& z) {
	return ::max (::max (x, y), z);
}
int main (void) {
	cout << ::max (123, 456) << endl;
	cout << ::max (1.23, 4.56) << endl;
	cout << ::max ("hello", "world") << endl;
	/*
	cout << ::max (string ("hello"),
		string ("world")) << endl;
	cout << ::max<string> ("hello", "world")
		<< endl;
	*/
	char const* a = "ABC";
	char const* b = "AB";
	char const* c = "A";
	char const* const& res = ::max (a, b, c);
	cout << res << endl; // ABC
	char const* d = "123";
	char const* e = "12";
	char const* f = "1";
	::max (d, e, f);
	cout << res << endl; // ?
	return 0;
}

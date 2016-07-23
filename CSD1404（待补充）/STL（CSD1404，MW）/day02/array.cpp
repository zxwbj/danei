#include <iostream>
#include <stdexcept>
using namespace std;
template<typename T = char, size_t S = 10>
class Array {
public:
	T& operator[] (size_t i) {
		if (i >= S)
			throw out_of_range ("数组下标越界！");
		return m_array[i];
	}
	const T& operator[] (size_t i) const {
		return const_cast<Array&> (*this)[i];
	}
	size_t size (void) const {
		return S;
	}
private:
	T m_array[S];
};
// 模板的非类型参数可以是整数类型
// char/short/int/long/long long及其unsigned
// 版本
template<char VAT>
void foo (void) {
	cout << VAT << endl;
}
/* 模板的非类型参数不能是浮点类型
	 float/double/long double
template<double VAT>
void bar (void) {
	cout << VAT << endl;
}
*/
/* 模板的非类型参数不能是类类型对象
template<string VAT>
void hum (void) {
	cout << VAT << endl;
}
*/
template<char const* VAT>
void fun (void) {
	cout << VAT << endl;
}
char const* g_global = "Hello, World !";
static char g_static[] = "Hello, World !";
char g_extern[] = "Hello, World !";
int main (void) {
	try {
//	Array<int, 5> a1;
//	Array<int, 2+3> a1;
//	size_t S = 5;
		const size_t S = 5;
//	const volatile size_t S = 5;
		Array<int, S> a1;
		for (size_t i = 0; i < 5; ++i)
			a1[i] = i+1;
		for (size_t i = 0; i < a1.size (); ++i)
			cout << a1[i] << ' ';
		cout << endl;
		a1[5] = 6;
	}
	catch (exception& ex) {
		cout << ex.what () << endl;
	}
	Array<Array<Array<int, 5>, 4>, 3> aaa;
	for (size_t i = 0; i < aaa.size (); ++i)
		for (size_t j = 0; j < aaa[i].size ();
			++j)
			for (size_t k = 0;
				k < aaa[i][j].size (); ++k)
				aaa[i][j][k] =
					(i+1)*100 + (j+1)*10 + (k+1);
	for (size_t i = 0; i < aaa.size (); ++i) {
		for (size_t j = 0; j < aaa[i].size ();
			++j) {
			for (size_t k = 0;
				k < aaa[i][j].size (); ++k)
				cout << aaa[i][j][k] << ' ';
			cout << endl;
		}
		cout << endl;
	}
	Array<> ac; // Array<char, 10> ac;
	for (size_t i = 0; i < ac.size (); ++i)
		ac[i] = 'A' + i;
	for (size_t i = 0; i < ac.size (); ++i)
		cout << ac[i];
	cout << endl;
	foo<'C'> ();
//bar<1.2> ();
//hum<"Hello, World !"> ();
//传递给模板的非类型参数不能是字面值字符串
//fun<"Hello, World"> ();
//传递给模板的非类型参数不能是全局指针
//fun<g_global> ();
//传递给模板的非类型参数不能是静态数组
//fun<g_static> ();
//传递给模板的非类型参数可以是外部数组
	fun<g_extern> ();
	return 0;
}

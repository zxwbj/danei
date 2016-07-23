#include <cstring>
#include <iostream>
using namespace std;
// 基本版本
template<typename T>
class Comparator {
public:
	Comparator (T const& x, T const& y) :
		m_x (x), m_y (y) {}
	T const& max (void) const {
		return m_x < m_y ? m_y : m_x;
	}
	T const& min (void) const {
		return m_x < m_y ? m_x : m_y;
	}
private:
	T const& m_x;
	T const& m_y;
};
/*
// 针对char const*类型的全类特化版本
template<>
class Comparator<char const*> {
public:
	Comparator (char const* const& x,
		char const* const& y) :
		m_x (x), m_y (y) {}
	char const* const& zuidazhi (void) const {
		cout << "特化版本的max()" << endl;
		return strcmp (m_x, m_y) < 0 ? m_y : m_x;
	}
	char const* const& zuixiaozhi (void) const {
		cout << "特化版本的min()" << endl;
		return strcmp (m_y, m_x) < 0 ? m_y : m_x;
	}
private:
	char const* const& m_x;
	char const* const& m_y;
};
*/
// 针对char const*类型的成员特化
template<> char const* const&
Comparator<char const*>::max (void) const {
		cout << "特化版本的max()" << endl;
		return strcmp (m_x, m_y) < 0 ? m_y : m_x;
}
template<> char const* const&
Comparator<char const*>::min (void) const {
		cout << "特化版本的min()" << endl;
		return strcmp (m_y, m_x) < 0 ? m_y : m_x;
}
int main (void) {
	Comparator<int> ci (123, 456);
	cout << ci.max () << ' '
		<< ci.min () << endl;
	Comparator<double> cd (1.23, 4.56);
	cout << cd.max () << ' '
		<< cd.min () << endl;
	string x = "hello";
	string y = "world";
	Comparator<string> cs (x, y);
	cout << cs.max () << ' '
		<< cs.min () << endl;
	Comparator<char const*> cp ("hello",
		"world");
	/*
	cout << cp.zuidazhi () << ' '
		<< cp.zuixiaozhi () << endl;
	*/
	cout << cp.max () << ' '
		<< cp.min () << endl;
	return 0;
}

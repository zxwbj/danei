#include <iostream>
#include <typeinfo>
using namespace std;
// 类模板
/*
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
	void foo (void) {}
private:
	T m_x;
	T m_y;
};
*/
template<typename T>
class Comparator {
public:
	Comparator (T const&, T const&);
	T const& max (void) const;
	T const& min (void) const;
	void foo (void);
private:
	T m_x;
	T m_y;
};
template<typename T>
Comparator<T>::Comparator (T const& x,
	T const& y) : m_x (x), m_y (y) {}
template<typename T>
T const& Comparator<T>::max (void) const {
	return m_x < m_y ? m_y : m_x;
}
template<typename T>
T const& Comparator<T>::min (void) const {
	return m_y > m_x ? m_x : m_y;
}
template<typename T>
void Comparator<T>::foo (void) {
  cout << "Comparator<" << typeid (T).name ()
		<< ">::foo()" << endl;
}
class Integer {
public:
	Integer (int data = 0) : m_data (data) {}
	int const& value (void) const {
		return m_data;
	}
	bool operator< (Integer const& rhs) const {
		return m_data < rhs.m_data;
	}
private:
	int m_data;
};
int main (void) {
	Comparator<int> ci (123, 456);
	cout << ci.max () << ' '
		<< ci.min () << endl;
	ci.foo ();
	Comparator<double> cd (1.23, 4.56);
	cout << cd.max () << ' '
		<< cd.min () << endl;
	cd.foo ();
	Comparator<string> cs ("hello", "world");
	cout << cs.max () << ' '
		<< cs.min () << endl;
	cs.foo ();
	Comparator<Integer> cn (123, 456);
	cn.foo ();
	cout << cn.max ().value () << endl;
	return 0;
}

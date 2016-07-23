#include <iostream>
using namespace std;
/*
template<typename X>
class A {
public:
	template<typename Y>
	class B {
	public:
		template<typename Z>
		void foo (Z const& z) {
			cout << z << endl;
		}
		Y m_y;
	};
	X m_x;
};
*/
template<typename X>
class A {
public:
	template<typename Y>
	class B;
	X m_x;
};
template<typename X>
	template<typename Y>
class A<X>::B {
public:
	template<typename Z>
	void foo (Z const& z);
	Y m_y;
};
template<typename X>
	template<typename Y>
		template<typename Z>
void A<X>::B<Y>::foo (Z const& z) {
	cout << z << endl;
}
int main (void) {
	A<char>::B<short> b;
	b.foo<int> (123);
	return 0;
}

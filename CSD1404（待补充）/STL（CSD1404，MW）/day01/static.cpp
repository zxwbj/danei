#include <iostream>
using namespace std;
class A {
public:
	void printAddr (void) const {
		cout << "A::m_i的地址：" << &m_i << endl;
	}
private:
	static int m_i;
};
int A::m_i;
template<typename T>
class B {
public:
	void printAddr (void) const {
		cout << "B::m_i的地址：" << &m_i << endl;
	}
private:
	static int m_i;
};
template<typename T>
int B<T>::m_i;
int main (void) {
	A a1;
	A a2;
	A a3;
	a1.printAddr ();
	a2.printAddr ();
	a3.printAddr ();
	B<char> b1;
	B<short> b2;
	B<int> b3, b4;
	b1.printAddr ();
	b2.printAddr ();
	b3.printAddr ();
	b4.printAddr ();
	return 0;
}

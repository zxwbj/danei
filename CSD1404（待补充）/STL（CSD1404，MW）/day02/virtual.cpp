#include <iostream>
using namespace std;
template<typename T>
class A {
public:
	virtual void foo (void) {
		cout << "A::foo()" << endl;
	}
	template<typename S>
	/*virtual*/void bar (void) {}
};
template<typename T>
class B : public A<T> {
public:
	void foo (void) {
		cout << "B::foo()" << endl;
	}
};
int main (void) {
	B<int> b;
	A<int>& a = b;
	a.foo ();
	a.bar<int> ();
	a.bar<string> ();
	return 0;
}


#include <iostream>
#include <typeinfo>
using namespace std;
class A {
public:
	class B {
	public:
		void foo (void) const {
			cout << typeid (*this).name () << endl;
		}
	};
};
template<typename T>
void bar (void) {
	typename T::B b;
	b.foo ();
}
int main (void) {
	A::B b;
	b.foo ();
	bar<A> ();
	return 0;
}

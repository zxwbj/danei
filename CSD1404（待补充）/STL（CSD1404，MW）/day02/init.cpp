#include <iostream>
using namespace std;
template<typename T>
void foo (void) {
//T t;
	T t = T ();
	cout << '[' << t << ']' << endl;
}
int main (void) {
	foo<string> ();
	foo<int> ();
	foo<double> ();
	foo<void*> ();
	int i = int ();
	double d = double ();
	typedef void* PVOID;
	void* p = PVOID ();
	cout << i << ' ' << d << ' ' << p << endl;
	return 0;
}

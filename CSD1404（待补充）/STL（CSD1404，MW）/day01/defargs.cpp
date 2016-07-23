#include <iostream>
#include <typeinfo>
using namespace std;
template<typename T1 = char,
	typename T2 = short, typename T3 = int>
/*
template<typename T1 = char,
	typename T2, typename T3 = int>
template<typename T1 = char,
	typename T2 = short, typename T3>
*/
class A {
public:
	static void printType (void) {
		cout << typeid (T1).name () << ','
			<< typeid (T2).name () << ','
			<< typeid (T3).name () << endl;
	}
};
/*
template<typename T1, typename T2 = int>
void foo (T1 const& t1, T2 const& t2) {}
*/
int main (void) {
	A<char, short, int>::printType ();
	A<char, short>::printType ();
	A<char>::printType ();
	A<>::printType ();
	/*
	A<, short, >::printType ();
	*/
	/*
	foo ('A', 1.23);
	*/
	return 0;
}

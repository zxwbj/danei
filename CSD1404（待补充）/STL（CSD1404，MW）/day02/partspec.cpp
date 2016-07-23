#include <iostream>
using namespace std;
// 基本版本
template<typename T1, typename T2>
class Dual {
public:
	static void printType (void) {
		cout << "Dual<T1,T2>" << endl;
	}
};
// 针对第二个类型参数取short的局部特化版本
template<typename T>
class Dual<T, short> {
public:
	static void printType (void) {
		cout << "Dual<T,short>" << endl;
	}
};
// 针对两个类型参数取相同类型的局部特化版本
template<typename T>
class Dual<T, T> {
public:
	static void printType (void) {
		cout << "Dual<T,T>" << endl;
	}
};
// 针对两个类型参数都取指针的局部特化版本
template<typename T1, typename T2>
class Dual<T1*, T2*> {
public:
	static void printType (void) {
		cout << "Dual<T1*,T2*>" << endl;
	}
};
// 针对两个类型参数取同类型指针的局部特化版本
template<typename T>
class Dual<T*, T*> {
public:
	static void printType (void) {
		cout << "Dual<T*,T*>" << endl;
	}
};
int main (void) {
	Dual<int, char>::printType ();
	Dual<int, short>::printType ();
	Dual<int, int>::printType ();
	Dual<int**, char*****>::printType ();
	Dual<int*, int*>::printType ();
	return 0;
}

#include <iostream>
using namespace std;
// 定义函数模板
template<typename T>
T max (T x, T y) {
	return x > y ? x : y;
}
class Integer {
public:
	Integer (int data = 0) : m_data (data) {}
	int& value (void) {
		return m_data;
	}
	bool operator> (Integer const& rhs) const {
		return m_data > rhs.m_data;
	}
private:
	int m_data;
};
int main (void) {
//cout << ::max<int> (123, 456) << endl;
	cout << ::max (123, 456) << endl;
//cout << ::max<double> (1.23, 4.56) << endl;
	cout << ::max (1.23, 4.56) << endl;
//cout << ::max<string> ("hello", "world")
//	<< endl;
	cout << ::max (string ("hello"),
		string ("world")) << endl;
	Integer a (123), b (456);
//cout << ::max<Integer> (a, b).value ()
//	<< endl;
	cout << ::max (a, b).value () << endl;
	return 0;
}

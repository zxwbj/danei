#include <iostream>
#include <sstream>
using namespace std;
template<typename K, typename V>
class Pair {
public:
	Pair (K const& k, V const& v) :
		m_k (k), m_v (v) {}
	template<typename S>
	string toString (S const& sep) const {
		ostringstream oss;
		oss << m_k << sep << m_v;
		return oss.str ();
	}
private:
	K m_k;
	V m_v;
};
template<typename K, typename V>
void print (Pair<K, V> const& pair) {
	// 调用对象pair依赖于模板参数K和V，
	// template关键字意在防止编译器误将其后的
	// "<"和">"理解为小于号和大于号
	cout << pair.template toString<char> ('=')
		<< endl;
}
template<typename K, typename V>
void print (Pair<K, V> const* pair) {
	cout << pair->template toString<char> ('=')
		<< endl;
}
int main (void) {
	Pair<string, double> pair ("PAI", 3.14);
	print (pair);
	print (&pair);
	return 0;
}

#include <iostream>
using namespace std;
template<typename T>
class Element {
public:
	Element (T const& t) : m_t (t) {}
	T m_t;
};
template<typename K, typename V,
	template<typename> class E>
class Pair {
public:
	Pair (K const& k, V const& v) :
		m_k (k), m_v (v) {}
	E<K> m_k; // Element<string> m_k;
	E<V> m_v; // Element<double> m_v;
};
int main (void) {
	Pair<string, double, Element> pair ("PAI",
		3.14);
	cout << pair.m_k.m_t << '='
		<< pair.m_v.m_t << endl;
	return 0;
}

#include <iostream>
#include <stack>
#include <vector>
#include <list>
using namespace std;
template<typename E, typename C>
class Stack {
public:
	E& top (void) {
		return m_c.back ();
	}
	void push (E const& e) {
		m_c.push_back (e);
	}
	void pop (void) {
		m_c.pop_back ();
	}
	size_t size (void) const {
		return m_c.size ();
	}
	bool empty (void) const {
		return m_c.empty ();
	}
private:
	C m_c;
};
int main (void) {
//Stack<string, vector<string> > ss;
//Stack<string, list<string> > ss;
	stack<string> ss;
	ss.push ("饭");
	ss.push ("吃");
	ss.push ("要");
	ss.push ("我");
	while (! ss.empty ()) {
		cout << ss.top ();
		ss.pop ();
	}
	cout << endl;
	return 0;
}

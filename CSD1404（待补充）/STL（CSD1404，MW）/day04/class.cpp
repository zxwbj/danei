#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Tracer {
public:
	Tracer (void) {
		cout << "缺省构造：" << this << endl;
	}
	Tracer (Tracer const& that) {
		cout << "拷贝构造：" << &that << "->"
			<< this << endl;
	}
	Tracer& operator= (Tracer const& rhs) {
		cout << "拷贝赋值：" << &rhs << "->"
			<< this << endl;
	}
	~Tracer (void) {
		cout << "析构函数：" << this << endl;
	}
	bool operator== (Tracer const& rhs) const {
		cout << "判断运算：" << &rhs << "=="
			<< this << endl;
		return true;
	}
	bool operator< (Tracer const& rhs) const {
		cout << "小于比较：" << this << "<"
			<< &rhs << endl;
		return true;
	}
};
int main (void) {
	cout << "-------- 1 --------" << endl;
	vector<Tracer> vt (3);
	cout << "-------- 2 --------" << endl;
	vt.push_back (Tracer ());
	cout << "-------- 3 --------" << endl;
	vt.erase (vt.begin ());
	cout << "-------- 4 --------" << endl;
	find (vt.begin (), vt.end (), Tracer ());
	cout << "-------- 5 --------" << endl;
	sort (vt.begin (), vt.end ());
	cout << "-------- X --------" << endl;
	return 0;
}

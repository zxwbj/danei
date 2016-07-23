#include <vector>
#include <algorithm>
#include "print.h"
class Integer {
public:
	Integer (int data = 0) : m_data (data) {}
	friend ostream& operator<< (ostream& os,
		Integer const& integer) {
		return os << integer.m_data;
	}
	bool operator< (Integer const& rhs) const {
		return m_data < rhs.m_data;
	}
private:
	int m_data;
	friend class IntCmp;
};
class IntCmp {
public:
	bool operator() (Integer const& x,
		Integer const& y) const {
		return x.m_data > y.m_data;
	}
};
int main (void) {
	vector<int> vi;
	vi.push_back (10);
	vi.push_back (20);
	vi.push_back (30);
	vi.push_back (20);
	vi.push_back (50);
	vector<int>::iterator it = find (
		vi.begin () + 2, vi.end (), 20/*25*/);
	if (it == vi.end ())
		cout << "没找到！" << endl;
	else
		cout << "找到了：" << *it << ", "
			<< *(it+1) << endl;
	vector<Integer> vn;
	vn.push_back (50);
	vn.push_back (20);
	vn.push_back (30);
	vn.push_back (20);
	vn.push_back (10);
	sort (vn.begin (), vn.end ());
	print (vn.begin (), vn.end ());
	sort (vn.begin (), vn.end (), IntCmp ());
	print (vn.begin (), vn.end ());
	return 0;
}

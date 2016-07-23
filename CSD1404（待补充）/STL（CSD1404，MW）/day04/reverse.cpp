#include <vector>
#include "print.h"
int main (void) {
	int a[] = {10, 20, 30, 40, 50};
	vector<int> vi (a, a + 5);
	vector<int>::reverse_iterator it;
	for (it = vi.rbegin (); it != vi.rend ();
		++it)
		cout << *it << ' ';
	cout << endl;
	it = vi.rbegin ();
	++*(it+1);
	print (vi.begin (), vi.end ());
	it = vi.rend ();
	it -= 2;
	--*it;
	print (vi.begin (), vi.end ());
	vector<int> v2 = vi; // 拷贝构造
	print (v2.begin (), v2.end ());
	v2[0] = 15;
	vi[0] = 25;
	print (vi.begin (), vi.end ());
	print (v2.begin (), v2.end ());
}

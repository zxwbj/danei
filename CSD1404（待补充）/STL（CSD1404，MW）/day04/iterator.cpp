#include <vector>
#include "print.h"
int main (void) {
	vector<int> vi (10);
//vi[4] = 5;
	vector<int>::iterator it = vi.begin ();
//*(it + 4) = 5;
	it += 4;
	*it = 5;
	print (vi.begin (), vi.end ());
	it = vi.end ();
//++*(it - 6);
	it -= 6;
	++*it;
	print (vi.begin (), vi.end ());
	cout << vi.end () - vi.begin () << endl;
	it = vi.begin () + 1;
	vector<int>::iterator it2 = it + 2;
	cout << boolalpha << (it < it2) << endl;
	return 0;
}

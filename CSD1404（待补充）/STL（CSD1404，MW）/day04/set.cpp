#include <iostream>
#include <set>
using namespace std;
int main (void) {
	set<int> si;
	si.insert (10);
	si.insert (20);
	si.insert (30);
	si.insert (20);
	si.insert (10);
	for (set<int>::iterator it = si.begin ();
		it != si.end (); ++it)
		cout << *it << ' ';
	cout << endl;
	return 0;
}

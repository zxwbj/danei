#include <iostream>
#include <vector>
using namespace std;
void print (vector<int> const& vec) {
	cout << "大小：" << vec.size () << endl;
	cout << "容量：" << vec.capacity () << endl;
	cout << "元素：";
	for (vector<int>::const_iterator it =
		vec.begin (); it != vec.end (); ++it)
		cout << *it << ' ';
	cout << endl;
}
int main (void) {
	vector<int> vi;
	print (vi);
	vi.push_back (1);
	print (vi);
	vi.push_back (2);
	print (vi);
	vi.push_back (3);
	print (vi);
	vi.push_back (4);
	print (vi);
	vi.push_back (5);
	print (vi);
	vi.push_back (6);
	vi.push_back (7);
	vi.push_back (8);
	print (vi);
	vi.push_back (9);
	print (vi);
	vi.pop_back ();
	print (vi);
	vi.resize (3);
	print (vi);
	vi.clear ();
	print (vi);
	vi.reserve (100);
	print (vi);
	vi.reserve (2);
	print (vi);
	return 0;
}

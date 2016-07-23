#include <list>
#include <algorithm>
#include "print.h"
class IntCmp {
public:
	bool operator() (int x, int y) const {
		return x > y;
	}
};
int main (void) {
	list<int> li;
	li.push_back (10);
	li.push_back (20);
	li.push_back (30);
	li.push_back (20);
	li.push_back (40);
	li.push_back (20);
	li.push_back (50);
	li.push_back (20);
	print (li.begin (), li.end ());
	li.remove (20);
	print (li.begin (), li.end ());
	int a[] = {10,20,20,20,30,20,20,40,20,50};
	li = list<int> (a, a + sizeof (a) /
		sizeof (a[0]));
	print (li.begin (), li.end ());
	li.unique ();
	print (li.begin (), li.end ());
	list<int> l1;
	l1.push_back (10);
	l1.push_back (20);
	l1.push_back (30);
	list<int> l2;
	l2.push_back (1000);
	l2.push_back (2000);
	l2.push_back (3000);
	l2.push_back (4000);
	cout << "l1：";
	print (l1.begin (), l1.end ());
	cout << "l2：";
	print (l2.begin (), l2.end ());
	list<int>::iterator pos = l1.begin ();
	++pos;
//l1.splice (pos, l2);
//list<int>::iterator del = l2.begin ();
//++++del;
//l1.splice (pos, l2, del);
	list<int>::iterator begin = l2.begin ();
	++begin;
	list<int>::iterator end = begin;
	++++end;
	l1.splice (pos, l2, begin, end);
	cout << "l1：";
	print (l1.begin (), l1.end ());
	cout << "l2：";
	print (l2.begin (), l2.end ());
	list<int> l3;
	l3.push_front (17);
	l3.push_front (23);
	l3.push_front (29);
	l3.push_front (36);
	l3.push_front (48);
	list<int> l4;
	l4.push_front (11);
	l4.push_front (37);
	l4.push_front (66);
	cout << "l3：";
	print (l3.begin (), l3.end ());
	cout << "l4：";
	print (l4.begin (), l4.end ());
	l3.merge (l4, IntCmp ());
	cout << "l3：";
	print (l3.begin (), l3.end ());
	cout << "l4：";
	print (l4.begin (), l4.end ());
	l3.sort ();
	print (l3.begin (), l3.end ());
	l3.sort (IntCmp ());
	print (l3.begin (), l3.end ());
//sort (l3.begin (), l3.end ());
	return 0;
}

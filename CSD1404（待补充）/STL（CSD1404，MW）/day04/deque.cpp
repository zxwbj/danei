#include <deque>
#include <algorithm>
#include "print.h"
int main (void) {
	deque<int> di;
	di.push_back (50);
	di.push_back (60);
	print (di.begin (), di.end ()); // 50 60
	di.push_front (40);
	di.push_front (30);
	print (di.begin (), di.end ());
	// 30 40 50 60
	di.pop_back ();
	print (di.begin (), di.end ());
	// 30 40 50
	di.pop_front ();
	print (di.begin (), di.end ());
	// 40 50
	di.push_back (60);
	print (di.begin (), di.end ());
	di.erase (find (di.begin(), di.end(), 50));
	print (di.begin (), di.end ()); // 40 60
	di.insert (di.begin (), 30);
	print (di.begin (), di.end ()); // 30 40 60
	di.resize (5);
	di[3] = 70;
	di[4] = 80;
	print (di.begin (), di.end ());
	// 30 40 60 70 80
	*(di.begin () + 2) -= 10;
	print (di.begin (), di.end ());
	// 30 40 50 70 80
	sort (di.rbegin (), di.rend ());
	print (di.begin (), di.end ());
	// 80 70 50 40 30
	/*
	cout << di.capacity () << endl;
	di.reserve (10);
	*/
	return 0;
}

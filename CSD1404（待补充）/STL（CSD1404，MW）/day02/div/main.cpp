#include <iostream>
using namespace std;
#include "comp.h"
int main (void) {
	int x = 123, y = 456;
	Comparator<int> comp (x, y);
	cout << comp.max () << ' ' << comp.min ()
		<< endl;
	cout << ::max (x, y) << ' ' << ::min (x, y)
		<< endl;
	return 0;
}

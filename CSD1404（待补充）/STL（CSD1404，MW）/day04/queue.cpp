#include <iostream>
#include <queue>
#include <list>
#include <vector>
using namespace std;
int main (void) {
//queue<string, list<string> > qs;
	queue<string> qs;
//queue<string, vector<string> > qs;
	qs.push ("我");
	qs.push ("要");
	qs.push ("工");
	qs.push ("作");
	qs.push ("！");
	while (! qs.empty ()) {
		cout << qs.front ();
		qs.pop ();
	}
	cout << endl;
	return 0;
}

#include <iostream>
using namespace std;
/*static*/  int  var_x=1000;
/* 相当于c中static 的效果 */
namespace {
    int  var_y=200;
}
int main(){
    cout << var_x << endl;
    cout << ::var_x << endl;
    cout << var_y << endl;
    cout << ::var_y << endl;
    int   x=123;
    cout << x << endl;
	 //	cout << ::x << endl;
}


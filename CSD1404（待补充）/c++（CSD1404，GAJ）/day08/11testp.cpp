#include <iostream>
using namespace std;
class A{
    public:
		int  *x;
		int  *y;
};
int main(){
    A  a;
		a.x=reinterpret_cast<int*>(0xbf0001);
		a.y=reinterpret_cast<int*>(0xbf0009);
    int *pi=(int*)&a;
		cout << pi << endl;
		cout << hex << *pi << endl;
}


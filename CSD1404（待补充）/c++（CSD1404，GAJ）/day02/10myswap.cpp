#include <iostream>
using namespace std;
void  myswap(int& x,int& y){
    int t=x;
		x=y;
		y=t;
}
int main(){
    int x=100;
		int y=123;
		myswap(x,y);
   /* int t=x;
		x=y;
		y=t;*/
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
}


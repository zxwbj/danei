#include <iostream>
using namespace std;
int main(){
    int  a=100;
		int&  ra=a;
    a=1;
		cout << ra << endl;
		cout << a << endl;
		int&  rra=ra;
		a=99;
		cout << ra << endl;
		cout << rra << endl;
		cout << a << endl;
		int   b=1001;
    // int& ra=b; 
		/* 这仅仅是把 b的值赋值给 ra  */
		ra=b;
    
}



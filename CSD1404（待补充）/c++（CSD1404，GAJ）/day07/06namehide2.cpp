#include <iostream>
using namespace std;
class A{
		public:
	  static  int  x;	 
};
class B:public A{  
    public:
		static  int  x;
};
int  B::x=100;
int  A::x=3;
int main(){
    cout << A::x << endl;
    cout << B::x << endl;
		cout << B::A::x << endl;
}


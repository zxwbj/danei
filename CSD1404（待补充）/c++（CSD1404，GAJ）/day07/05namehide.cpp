#include <iostream>
using namespace std;
class A{
    public:
		int  x;
		void  show(){
		    cout << x << endl;
		}
};
class B:public A{  
    public:
		int  x;		
		void  show(){
		    cout << "B  show()" << endl;
				cout << x << endl;
		}
};
int main(){
		B   b;
		b.x=101;
		b.show();
		/* 要调用A中对应的show */
    b.A::show();
}


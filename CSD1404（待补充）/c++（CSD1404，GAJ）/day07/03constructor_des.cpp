#include <iostream>
using namespace std;
class A{
    public:
		A(){ cout << "A()" << endl; }	
		A(int x){ cout << "A(int)" << endl; }	
		A(int x,int y){ cout << "A(int,int)" 
				<< endl; }	
    ~A(){ cout << "~A()"<< endl; }
};
class B:public A{
    public:
		B():A(1){ cout << "B()" << endl; }	
		B(int x):A(x,123){ cout << "B(int)" << endl; }	
    ~B(){ cout << "~B()"<< endl; }
};

int main(){
    //B  b;
    B  b2(100);
}



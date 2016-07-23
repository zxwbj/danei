#include <iostream>
using namespace std;
class A{
    public:
		A(){
		    cout << "A()" << "this=" << this 
						 << endl;
		}		
		void  show(){
		    cout << "show() " << this << endl;
		}
};
int main(){
    A   var_a;
		cout << "var_a  " << &var_a << endl;
		var_a.show();
    A   *var_b = new A();
		cout << "var_b  " << var_b << endl;
		var_b->show();

}


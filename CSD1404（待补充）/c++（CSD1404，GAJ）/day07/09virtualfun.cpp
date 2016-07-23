#include <iostream>
using namespace std;
class A{
    double  sal;
		public:
		virtual void  show(){ 
				cout << "show()" << endl;
		}
		virtual void  run(){
		    cout << "run()" << endl; 
		}
};
int main(){
    cout << sizeof(A) << endl;
}

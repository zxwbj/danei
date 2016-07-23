#include <iostream>
using namespace std;
class A{
    public:
		/*A(int x){
        cout << "A(int)" << endl;		
		}
		A(){
		    cout << "A()" << endl;
		}*/
		A(int x=0,int y=0){
		    cout << "A(int,int)" << endl;
		}
};
int main(){
    cout << sizeof(A) << endl; 
		A   a;
		A  *pa =new A();
    A   aa(1);
		A  *paa = new A(2);
		A   b(1,2);
		A  *pb=new A(100,200);
}


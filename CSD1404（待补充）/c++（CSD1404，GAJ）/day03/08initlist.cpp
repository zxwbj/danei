#include <iostream>
using namespace std;
class A{
    const int  x;
		int  y;
		int& z;
		public:
		A(int& z,int x=100,int y=123):z(z),
		   x(x),y(y){
		    //x=100;
		}
		void   show(){
		    cout << x << '/' << y << endl;
		}
};
int main(){
		int pz=100;
    A   a(pz);
		a.show();
}

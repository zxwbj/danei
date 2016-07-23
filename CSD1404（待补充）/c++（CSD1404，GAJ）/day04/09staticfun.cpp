#include <iostream>
using namespace std;
class A{
		public:
		int  x;
		static  int  y;
    public:
		void  fooa(/*A *this*/){
		    cout << "fooa()" << endl;
				cout << this->x << endl;
				cout << this->y << endl;
		}	
		static  void foob(){
		    cout << "foob()" << endl;
				// cout << x << endl;
				cout << y << endl;
		}
		private:
		static  void fooc(A *mythis){
		    cout << mythis->x << endl;
		}
};
int  A::y=1;
int main(){
    A   a;
		A::fooc(&a);
		a.fooa();
		A::foob();
		a.foob();
		cout << sizeof(A) << endl;
		cout << A::y << endl;
		a.y=101;
		cout << A::y << endl;
 }


#include <iostream>
using namespace std;
class  A{
    public:
		virtual  void   fooa(int x){
				cout << "fooa(int)" << endl;
		    cout << x << endl;
		}		
		virtual  void   foob(int x){
		    cout << "foob(int)" << endl;
				cout << x << endl;
		}
};
typedef void   (*VFUN)(A* mythis,int x);
typedef VFUN*  VTABLE;  
int main(){
   A   a;
	 VTABLE  vt=*((VTABLE*)&a);
   vt[0](&a,123);
   vt[1](&a,456);
   // vt[2](&a,456);
}



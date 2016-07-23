#include <iostream>
using namespace std;
class A{
		mutable int   data;
    public:
		A(){   }
		/* _ZN1A4showEv */
		void  show(){
		    cout << "show()" << endl;
		}	
		void  testa(){
		
		}
		/* _ZNK1A4showEv */
		void  show()const{
		    cout << "show() const" << endl;
				data=1001;
				cout << data << endl;
				//testa();
		}		
};
int main(){
    A  var_a;
		var_a.show();
   // const  A  var_b=var_a;
		const   A  var_b;
    var_b.show(); 
}


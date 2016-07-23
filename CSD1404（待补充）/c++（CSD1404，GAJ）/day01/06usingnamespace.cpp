#include <iostream>
using namespace std;
namespace  IBM{
    int   age=80;
    void  show(){
		    cout << "IBM  age is " << age << endl;
		} 
}

namespace  tarena{
    int  age=12;
    void  show();
}  
namespace tarena{
    void   show(){
		    cout << "tarena age is " << age 
						 << endl;
		}
}
using namespace  IBM;
//using namespace tarena;
int main(){
    tarena::show();
		show();
	 //age++;
	 // show();
}




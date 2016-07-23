#include <iostream>
using namespace std;
namespace  ns1{
    int   a=1;
    namespace ns2{
		    int  a=100;
				void  show(){ cout << a << endl;}
				namespace ns3{
				    void  show(){
						    cout << "this is ns3 show" << endl;
						}
				}
		}
}
/* 命名空间重命名  */
namespace  ns4=ns1::ns2::ns3;
int main(){
    cout << ns1::a << endl;
		cout << ns1::ns2::a << endl;
    ns1::ns2::show(); 
		using  ns1::ns2::ns3::show;
		show();
		ns4::show();
}




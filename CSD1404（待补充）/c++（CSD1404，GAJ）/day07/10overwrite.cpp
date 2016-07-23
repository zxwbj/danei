#include <iostream>
using namespace std;
class  A{
    public:
		void   show(){
	      cout << "show()" << endl;	
		}	
		virtual  void run(){
		    cout << "run()" << endl;
		}
};
class B:public A{  
    public:
		/* 名字隐藏 */		
		int  show(/*int x*/){
		    cout << "this is show()" << endl;
		}
		/* 这是函数重写 */
    void   run(){
		    cout << "this is run()" << endl;
		}
};
int main(){
    A *a=new B();
    a->show();
		a->run();
		A   aa;
		aa.run();
		B   b;
		b.run();
		A&   ta=b;
		ta.run();
}



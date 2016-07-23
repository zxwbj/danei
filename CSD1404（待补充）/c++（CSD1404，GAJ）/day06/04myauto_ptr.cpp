#include <iostream>
using  namespace std;
class A{
    public:
		A(){  cout << "A()" << endl; }	
		~A(){ cout << "~A()" << endl; }
		void  show(){ cout << "show A" << endl; }
};
/* 写一个智能指针类型 用来管理A类型的
	 指针对象 */
class  myauto_ptr{
    A  *data;
	  public:
		myauto_ptr(A *data=NULL):data(data){
		}
		~myauto_ptr(){ delete data;	}
		void  showmsg(){
		    cout << "showmsg()" << endl; 
		}
		/* -> */
    A*   operator->(){
		    //return  data;
				return  &**this;
		}
		/* *号重载 只要返回管理的指针对应的对象 */
    A&  operator*(){
		    return *data;
		}
};
void  foo(){
    A *pa = new  A();
		myauto_ptr  myptr(pa);
    myptr.showmsg();
		myptr->show();
		/* 编译器允许把下面的写法 
			 写成上面的形式 */
    myptr.operator->()->show();
		(*myptr).show();
}
int main(){
    foo();
}


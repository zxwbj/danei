#include <iostream>
using namespace std;
class A{
    int  *data;
		public:
		/* 构造函数中 分配内存 */
		A()/*:data(new int(10))*/{
		    data=new int(10);
				cout << "A()" << endl;
		}
		/* 析构函数 负责释放内存 */
		~A(){
        cout << "~A()" << endl;	
				delete  data;
		}
};
int main(){
    A *pa = new A[5];
    delete[]  pa;
		A   a;
		/* 语法上是允许手动调用析构函数的 */
		//a.~A();
		A *paa =new A();
		/* 在这里使用 paa  */
    delete  paa;
}




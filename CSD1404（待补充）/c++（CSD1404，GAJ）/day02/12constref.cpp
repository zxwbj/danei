#include <iostream>
using namespace std;
/* 引用类型的参数 加一个const 是为了增强
   函数的兼容性 除非要在函数内修改参数 */
void  printRef(const int& ra){
    cout << ra << endl;
}
/* const 作用就是防止函数内部对x进行修改 */
void  printValue(/*const*/ int x){  }
int main(){
    /* const */ int  a=100;
		printRef(a);
		printRef(99);
		/* const 在星号前 代表不能通过pa 修改
			 指向的内存中的值 但可以改变pa的
		   指向 */
    const  int *pa=&a;
    // *pa=200;
    int  b=200;
		pa=&b;
		/* pra 只能指向 a  不能指向b 
		   但可以通过 pra修改值 */
    int *const pra=&a;
    *pra=199;
    cout << a << endl;
}


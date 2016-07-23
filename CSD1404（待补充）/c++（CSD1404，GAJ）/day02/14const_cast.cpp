#include <iostream>
using namespace std;
int main(){
    volatile  const  int  a=100;
		//int *pa=(int*)&a;
		int *pa=const_cast<int*>(&a);
		*pa=200;
		cout << *pa << endl;
		cout << a << endl;
		/* 对内存进行重新解释 最接近强制类型转换 */
		// reinterpret_cast<类型>(变量); 
}


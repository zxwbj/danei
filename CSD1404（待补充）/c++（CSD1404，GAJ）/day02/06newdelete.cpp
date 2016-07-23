#include <iostream>
using namespace std;
int main(){
    int *pi=new int;
		cout << "*pi=" << *pi << endl;
		*pi=100;
		cout << "*pi=" << *pi << endl;
		delete  pi;
		cout << "*pi=" << *pi << endl;
    pi=NULL;
		/* 申请一个double类型对应大小的堆空间 
		   然后赋值 使用这块空间  最后释放空间 */
		double  *pd=new double(7.7);
		cout << "pd=" << *pd  << endl;
    *pd=123.5;
		cout << "pd=" << *pd << endl;
		delete  pd;
		cout << "pd=" << *pd << endl;

}


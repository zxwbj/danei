#include <iostream>
#include <cstdlib>
#include <stdexcept>
using namespace std;
int main(){
    void *pi=malloc(0xffffffff);
		cout << "pi=" << pi << endl;
		try{
		int *pii=new int[0xffffffff];
		cout << "pii=" << pii << endl;
		}catch(bad_alloc& e){
		cout << e.what() << endl;
		cout << "内存分配失败 " << endl;
		}
		cout << "重新申请内存" << endl;
    string   abc="hello";
		cout << abc[0] << endl;
		cout << abc.at(0) << endl;
		cout << abc[5] << endl;
		try{
		cout << abc.at(5) << endl;
		}catch(out_of_range& e){
		cout << e.what() << endl;
		cout << "访问下标越界 " << endl;
		}
}


#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
/* 对foo函数 可能会抛出哪些异常 做说明 */
void   foo()throw(int,double,const char*){
    /* 0  正常  1  2  3 */
    int  temp=rand()%4;
		if(0==temp){
		    cout << "程序正常执行" << endl;
		}else if(1==temp){
		    throw 1;
		}else if(2==temp){
		    throw 2.5;
		}else {
		    throw "其它情况";
		}
}
int main(){
    srand(time(NULL));
    try{
		foo();
		cout << "foo over!" << endl;
		}catch(int e){
		cout << "整数形式的异常" << e << endl;
		}catch(const char* e){
		cout << "字符串形式的异常" << endl;
		cout << e << endl;
		}catch(double e){
		cout << "出现浮点数异常" << endl;
		cout << e << endl;
		}catch(...){
		cout << "未知的其它问题" << endl; 
		}
		cout << "程序继续执行" << endl;
}




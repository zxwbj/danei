#include <iostream>
using namespace std;
/*int  getmax(int x,int y){
    return  x>y?x:y;
}*/
/* 不能返回局部变量的引用  
   可以返回  全局 静态 堆内存 引用 */
int&  getmax(int& x,int& y){
    return  x>y?x:y;
}
int&  getNum(){
    static int x=1;
		return x;
}
int main(){
    int x=10;
		int y=20;
		//int t=getmax(x,y);
    getmax(x,y)=100;
    cout << y << endl;
		getNum();
}


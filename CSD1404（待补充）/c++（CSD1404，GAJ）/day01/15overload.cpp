#include <iostream>
using namespace std;
int  add(int x,int y){
    cout << "add(int,int)" << endl;
		return  x+y;
}
double add(int x,double y){
    cout << "add(int,double)" << endl;
		return  x+y;
}
double add(double x,double y){
    cout << "add(double ,double)" << endl;
    return  x+y;
}
int main(){
    add(1.5,1.6);
    add(1,2);
		add(1,1.5);
    /* 定义一个函数指针 调用第三个函数 */
    double  (*padd)(double x,double y);
		padd=add;
		padd(1.5,1.6);
}



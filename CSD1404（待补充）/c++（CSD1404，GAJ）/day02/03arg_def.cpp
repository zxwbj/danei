#include  <iostream>
using namespace std;
void  show(int x=1,int y=2){
    cout << x << endl;
		cout << y << endl;
}
/* 设计一个函数 传入两个整数参数 返回最大值 */
int  getmax(int x=1,int y=0);
int main(){
		getmax();
    show();
		show(1);
		show(100,200);
}
int  getmax(int x,int y){
   return  x>y?x:y;
}


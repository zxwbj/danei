#include <iostream>
using namespace std;
int main(){
    char data[10];
		cout << cin << endl;
	  cin.getline(data,5);
		cout << data << endl;
		if(!cin){
		/* 复位 */		
		cin.clear();
		/*	清理缓冲区 */
		cin.ignore(200,'\n');
		}
    cout << cin << endl;
		/* 流对象出错自动变成0 拒绝IO */
		int  x;
		cin >> x;
		cout << x << endl;
}


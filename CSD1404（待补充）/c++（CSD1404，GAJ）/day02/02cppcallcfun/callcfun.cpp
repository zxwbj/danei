#include <iostream>
using namespace std;
extern "C" {
int  getmax(int x,int y);
int  getmin(int x,int y);
}
int main(){
    cout << getmax(1,100) << endl;
		cout << getmin(23,100) << endl;
}


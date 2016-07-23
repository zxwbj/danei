#include <iostream>
using namespace std;
inline int  getmax(int x,int y){
    return  x>y?x:y;
}
#define  GETMAX(X,Y) (((X)>(Y))?(X):(Y))
int main(){
    int  x=100;
		int  y=200;
		cout << getmax(x,y) << endl;
		cout << GETMAX(x,y) << endl;
}


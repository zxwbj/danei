#include <iostream>
using namespace std;
inline int  getmax(int x,int y){
    return  x>y?x:y;
}
int  getmin(int x,int y){
    return  x>y?y:x; 
}
int main(){
		getmax(1,2);
		getmin(100,200);
}

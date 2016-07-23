#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int   foo(){
    /* 0  正常  1  2  3 */
    int  temp=rand()%4;
		return  temp;
}
int main(){
    srand(time(NULL));
    int t=foo();
    if(t==0){
		    cout << "程序正常" << endl;
		}else{
		    cout << t << endl;
		}
}


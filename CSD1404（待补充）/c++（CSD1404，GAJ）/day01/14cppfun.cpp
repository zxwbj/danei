#include <iostream>
using namespace std;
void  foo(){
    cout << "foo()" << endl;
}
main(){
    foo();
    //foo(1);
    //foo(1,2);
    int  showNum(int x);
    showNum(100);
    showNum(1001);
}
int  showNum(int x){
    cout << "x=" << x << endl;
}


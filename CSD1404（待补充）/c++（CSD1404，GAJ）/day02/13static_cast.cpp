#include <iostream>
using namespace std;
int main(){
    int *pi=new int(100);
		void *pv=pi;
		int *pt=static_cast<int*>(pv);
		cout << *pt << endl;
}


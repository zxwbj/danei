#include <iostream>
using namespace std;
int main(){
    union {
		    int  x;
				char data[4];
		};
		/* '0' 48  'A' 65  'a' 97  */
    // x=0x31323334;
		x=0x41424344;
		for(int i=0;i<4;i++){
		    cout << data[i] << " ";
		}
		cout << endl;
}


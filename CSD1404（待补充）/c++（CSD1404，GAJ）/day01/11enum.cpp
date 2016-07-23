#include <iostream>
using namespace std;
enum  Direction{D_UP,D_DOWN,D_LEFT,D_RIGHT};
int main(){
    Direction dire=D_LEFT;
		int  x=dire;
		cout << x << endl;
		x=3;
		/* 这里体现了c++ 类型检查严格 */
		// dire=x;
		dire=D_RIGHT;
    switch(dire){
		    case D_UP:
				cout << "dire  is D_UP" << endl;
        break;
				case D_DOWN:
        cout << "dire is D_DOWN" << endl;
				break;
				case D_LEFT:
				cout << "dire is D_LEFT" << endl;
				break;
        case D_RIGHT:
				cout << "dire is D_RIGHT" << endl;
				break;
		}
}



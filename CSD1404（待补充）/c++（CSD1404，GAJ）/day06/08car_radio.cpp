#include <iostream>
using namespace std;
class Radio{
		public:
    int  type;
    int  color;
		void  rfun(){
		    cout << "听广播" << endl;
		}
};
class Car{
    public:
	  Radio   radio;
    int   wheels;
		void   carfun(){
		    cout << "车用来代步" << endl;
		}
};
int main(){
    Car   car;
		car.radio.rfun();
		car.carfun();
}




#include <iostream>
using namespace std;
class Phone{
    double   price;
		public:
		double  getPrice(){ return  price; }
		Phone(double  price=0.0):price(price){
				cout << "Phone()" << endl;
		}
    void   phone(){
		    cout << "打电话" << endl; 
		}
};
class Camera{
    double   price;
		public:
		double  getPrice(){ return  price; }
		Camera(double  price=0.0):price(price){
				cout << "Camera()" << endl;
		}
    void   carmerfun(){
		    cout << "拍视频" << endl; 
		}
};
class Mp3{
    double   price;
		public:
		double  getPrice(){ return  price; }
		Mp3(double  price=0.0):price(price){
				cout << "Mp3()" << endl;
		}
    void   mp3(){
		    cout << "播放音乐" << endl; 
		}
};
class IPhone:public Phone,public Mp3,public Camera{
    public:
	  IPhone(double p=0,double m=0,double c=0)
		:Phone(p),Mp3(m),Camera(c){
		
		}		
		/* 名字隐藏机制 */
		double  getPrice(){
		    return Phone::getPrice()
				+Camera::getPrice() +Mp3::getPrice();
		}
};
int main(){
 /*   Phone  phone(999);
		phone.phone();
		cout << phone.getPrice() << endl;*/
		IPhone   iphone6(999,51,3000);
    iphone6.phone();
		iphone6.mp3();
		cout << iphone6.Mp3::getPrice() << endl;
		cout << iphone6.Phone::getPrice() << endl;
		cout << iphone6.Camera::getPrice() << endl;
		cout << iphone6.getPrice() << endl; 
}




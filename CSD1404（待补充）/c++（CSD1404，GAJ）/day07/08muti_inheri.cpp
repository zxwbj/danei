#include <iostream>
using namespace std;
class  Product{
    double   price;
		public:
		double   getPrice(){return  price;}
		Product(double price=0.0):price(price){
		}
};
class Phone:virtual public  Product{
		public:
		Phone(double  price=0.0):Product(price){
				cout << "Phone()" << endl;
		}
    void   phone(){
		    cout << "打电话" << endl; 
		}
};
class Camera:virtual public Product{
    public:
		Camera(double  price=0.0):Product(price){
		}
		void   camerafun(){
		    cout << "拍视频" << endl;
		}
};
class Mp3:virtual  public Product{
		public:
		Mp3(double  price=0.0):Product(price){
		}		
		void  mp3fun(){
		    cout << "播放音乐" << endl;
		}
};
class IPhone:public Phone,public Mp3,
		public  Camera{
	  public:
		IPhone(double p=0,double m=0,
			  double c=0):Product(p+m+c){
		}		
};
int main(){
    cout << sizeof(Phone) << endl;
    cout << sizeof(Camera) << endl;
    Camera   camera(1999.5);
		cout << camera.getPrice() << endl;
		IPhone   iphone6(1500,50.5,3500);
		/* 只复制了最高层类的一份数据 不会冲突 */
		cout << iphone6.getPrice() << endl;
		cout << sizeof(iphone6) << endl;
}




#include <iostream>
using namespace std;
class Product{
    double   price;
		int      count;
		public:
		Product(){
		}
		Product(double price,int count):
		price(price),count(count){
		
		}
		/* 重载()  就可以使用函数对象 */
    double  operator()(double p,int c){
		    return  p*c;
		}
		/* 支持类型转换 */
		operator double(){
		    return  price;
		}
		/* 支持转换int  */
		operator int(){
		    return  count;
		}
};
void   showp(Product p){
   cout << p(100.5,5) << endl;
}
int main(){
    Product  apple;
    double price=apple(5888.5,3);
    cout << price << endl;
		showp(apple);
		Product  iphone6(5888.5,10);
    double  p=(double)iphone6;
    cout << p << endl;
		int     count=(int)iphone6;
		cout  << count << endl;
}


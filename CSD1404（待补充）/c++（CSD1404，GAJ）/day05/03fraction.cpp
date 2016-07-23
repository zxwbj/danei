#include <iostream>
using namespace std;
class  Fraction{
    public:
		int   x;
		int   y;
		Fraction(int x=0,int y=1):x(x),y(y){
		}
		void  show(){
        cout << x << '/' << y << endl;		
		}
		/* 写一个*的成员函数 fa*fb */
		Fraction  operator*(const Fraction& fb){
				 cout << "mem operator*" << endl; 
         return Fraction(this->x*fb.x,
								    this->y*fb.y);		
		}
};
Fraction   operator*(const Fraction& fa,
		const Fraction& fb){
    return  Fraction(fa.x*fb.x,fa.y*fb.y);
}
/* 设计一个函数 完成两个分数的相加  
   addFraction(fa,fb)   */
Fraction   addFraction(const Fraction& fa,
		const Fraction& fb){
		/*
    Fraction   temp;
		temp.x=fa.x*fb.y + fa.y*fb.x;
		temp.y=fa.y*fb.y;
		return  temp;*/
		return  Fraction(fa.x*fb.y + fa.y*fb.x,
						    fa.y*fb.y);
}
Fraction   operator+(const Fraction& fa,
		const Fraction& fb){
		return  Fraction(fa.x*fb.y + fa.y*fb.x,
						    fa.y*fb.y);
}
int main(){
    Fraction  fa(1,2);
		fa.show();
		Fraction  fb(1,3);
		fb.show();
		Fraction  fe=fa*fb;
		fe.show();
		Fraction  fc=addFraction(fa,fb);
		fc.show();
		Fraction  fd=fa+fb;
		fd.show();
}





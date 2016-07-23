#include <iostream>
using namespace std;
class  Fraction{
    int  x;
		int  y;
		public:
		Fraction(int x=0,int y=1):x(x),y(y){
		}
		Fraction  operator*(const Fraction& f){
		    return  Fraction(x*f.x,y*f.y);
		}
		Fraction  operator*(int f){
		    return  Fraction(x*f,y);
		}
		/* void  operator*=(const Fraction& f) */
    void   operator*=(const Fraction& f){
		    x*=f.x;
				y*=f.y;
		}

		friend  ostream&  operator<<(ostream& os,
				const Fraction& fa){
		    return  os << fa.x << '/' << fa.y;
		}
		friend  istream& operator>>(istream& is,
				 Fraction& fa);
    friend Fraction&   operator--
				(Fraction& f);
};
	  istream& operator>>(istream& is,
				 Fraction& fa){
		    cout << "请输入分子:";
				is >> fa.x;
        cout << "请输入分母:";
				is >> fa.y;
        return  is; 
		}
/*  前 -- */
Fraction&   operator--(Fraction& f){
    f.x-=f.y;
		return  f;
}
/* 后--  */
Fraction   operator--(Fraction& f,int){
    int temp=f.x;
		f.x-=f.y;
		return  Fraction(temp,f.y);
}
int main(){
    Fraction  fa(1,2);
		--fa;
		cout << fa << endl;
		cin >> fa;
		cout << fa  << endl;
		Fraction  fb=fa*100;
    cout << fb << endl;
}


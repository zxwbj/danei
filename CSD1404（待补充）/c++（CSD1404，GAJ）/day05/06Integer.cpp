#include <iostream>
using namespace std;
class Integer{
    int  data;
		public:
		Integer(int data):data(data){
		}
		void   show(){
		    cout << data << endl;
		}
		/* == 以值来判断 两个整数是否相等  */
		bool   operator==(const Integer& ib){
				//return  this==&ib;
		    return  data==ib.data;
		}
    friend ostream&  operator<<(ostream& os,
	  const Integer& ia);
    friend istream&  operator>>(istream& is,
		 Integer& ia);
};
/*void*/ ostream&   operator<<(ostream& os,
	  const Integer& ia){
    return  os << ia.data ;
}
/* 参考输出运算符 写出输入运算符 */
istream&  operator>>(istream& is,
		 Integer& ia){
   // return  is >> ia.data;
		 is >> ia.data;
		 return  cin;
}
int main(){
    Integer  ia(100);
		cin >> ia;
    ia.show();
		cout << ia << endl;
		cout << endl;
}




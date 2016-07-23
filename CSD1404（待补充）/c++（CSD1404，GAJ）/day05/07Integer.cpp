#include <iostream>
using namespace std;
class Integer{
    int  data;
		public:
		Integer(int data=0):data(data){
		}
		Integer operator!(){
		    return  Integer(!data); 
		}
		/* 提供一个 负号的重载 - */
		Integer operator-(){
		    return  Integer(-data);
		}
		/* 提供一个 前++的重载  */
    Integer&   operator++(){
		    //++data;
				data++;
				return *this;
		}
		/* 后++ 使用哑元区分 */
		const Integer operator++(int){
		   /* Integer  temp;
				temp.data=data;
        data++;
				return  temp;*/
				//return  Integer(data++);
				Integer  temp=*this;
        ++data;
				return temp;
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
    Integer  ia(1001);
		cout << ia << endl;
		cout << !!ia << endl;
		cout << ia << endl;
		cout << -(-ia) << endl;
		int  x=1;
		++++x;
		//x++++;
		cout << x << endl;
		Integer  ib(1);
		++++ib;
		cout << ib << endl;
		cout << ib++ << endl;
		cout << ib << endl;
}




#include <iostream>
using namespace std;
class Integer{
    int  data;
		public:
		Integer(int data=0):data(data){
		}
		void  show(){
		    cout << data << endl;
		}
		/* ia+=ib; */
		void  operator+=(const Integer& ib){
		    data+=ib.data; 
		}
		Integer   operator+(const Integer& ib){
		    return Integer(data+ib.data); 
		}
		friend Integer operator-
		(const Integer& ia,const Integer& ib);
    friend void   operator-=(Integer& ia,
				 const Integer& ib);
};
/* 在成员位置 提供相加等于的运算符函数 */
/* 在全局位置 提供相减等于的运算符函数 */
 void   operator-=(Integer& ia,
				 const Integer& ib){
		 ia.data-=ib.data;
 }
 Integer operator-
	(const Integer& ia,const Integer& ib){
			/* 单参构造规则 */
	    return  ia.data-ib.data;	
	}
int main(){
    Integer  ia(100);
		Integer  ib(1);
    /* 在成员位置 提供相加的运算符函数 */
		/* 在全局位置 提供相减的运算符函数 */
		Integer  ic=ia+ib;
    ic.show();
		Integer  id=ia-ib;
		id.show();
		ia-=ib;
    ia.show();
}



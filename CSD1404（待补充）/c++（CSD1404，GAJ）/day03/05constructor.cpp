#include <iostream>
#include <iomanip>
using namespace std;
class Date{
    int  year;
		int  month;
		int  day;
		public:
		/* 这就是构造函数  */
		Date(){
				cout << "Date()" << endl;
		    year=2014;
				month=1;
				day=1;
		}
		void   show(){
		    cout << setfill('0') << setw(4) <<
						year << '-' << setw(2) << month
						<< '-' << day << endl;
		}
};
int main(){
		/* 类型的实例化 */
    Date  date;
    Date  *pd=new Date();
    Date  *pd2=new Date;
		date.show();
		pd->show();
		/* 编译器会翻译成 函数声明 */
		Date  date2();
}



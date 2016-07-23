#include <iostream>
using namespace std;
struct  Date{
		/* 成员变量 */
    int   year;
		int   month;
		int   day;
		/* 成员函数 */
		void  show(){
		    cout << year << '-' << month 
						 << '-' << day << endl;
		}
};
/* 设计一个函数 用来显示一个日期变量的数据 */
void    showDate(Date  date){
    cout << date.year << '-' << date.month 
				 << '-' << date.day << endl;
}
struct  Emp{

};
int main(){
    Date  date={2014,7,4};
		cout << date.year << '-' << date.month 
				 << "-" << date.day << endl;
		showDate(date);
		date.show();
		cout << sizeof(Emp) << endl;
}


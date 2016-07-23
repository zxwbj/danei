#include <iostream>
using namespace std;
class Date;
void  show(Date* date);
class Date{
    int  year;
		int  month;
		int  day;
		public:
		Date(int year=2014,int month=1,int d=1){
		  /* 不使用初始化参数列表给成员变量赋值 */
		    this->year=year;
				this->month=month;
				// day=d;
				this->day=d;
		}
    void  setDate(int year=2014,int month=1,
				int day=1){
		    this->year=year;
				this->month=month;
				this->day=day;
		}
		void  show(){
		    cout << year << '-' << month << '-'
						<< day << endl; 
		}
		void  showSelf(){
				/* 当成员函数 和 全局函数重名时 
				 可以使用无名 命名空间区分 */
	      ::show(this);	
		}
		/*Date* */ Date&  addDay(){
         day++;		
				 return *this;
		}
};
/* 写一个全局函数 用来表现一个日期 参数使用
   Date* 类型 */
void  show(Date* date){
    date->show();
}
int main(){
    Date date;
    date.show();
		Date date2(2015,10,1);
		date2.show();
		date2.setDate(2017,7,9);
		date2.show();
		show(&date2);
		date2.showSelf();
		//date2.addDay()->addDay();
		date2.addDay().addDay();
		date2.show();
}




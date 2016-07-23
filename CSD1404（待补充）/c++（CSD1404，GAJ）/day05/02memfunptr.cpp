#include <iostream>
using namespace std;
class Date{
    int  year;
		int  month;
		int  day;
		public:
		Date(int year=2014,int month=1,int day=1)
			 :year(year),month(month){
		   this->day=day;  
		}
    int  getYear(){
		    return  year;
		}
    int  getMonth(){
		    return  month;
		}
};
int main(){
    Date   date(2014,7,10);
    int  (Date::*pmfun)();
    pmfun=&Date::getMonth;
    cout << (date.*pmfun)() << endl;
    Date  *date2=new Date(2015,10,1);
    cout << (date2->*pmfun)() << endl;
}

#include <iostream>
using namespace std;
struct  Date{
    int year;
		int month;
		int day;
		void  show(){
		    cout << year << '-' << month << '-'
						 << day  << endl;
		}
};
int main(){
    Date date;
		cout << &date << endl;
    Date *pd = new Date;
    cout << pd << endl;
		pd->year=2014;
		pd->month=7;
		pd->day=7;
    pd->show();
		// cout << *pd << endl;
		delete  pd;
}



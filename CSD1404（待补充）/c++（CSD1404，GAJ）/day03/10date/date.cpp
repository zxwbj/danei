    /*int  year;
		int  month;
		int  day;*/
#include "date.h"
#include <iostream>
using namespace std;
void  Date::setDate(int y,int m,int d){
		// this->year=year;
    year=y;
		month=m;
		day=d;
}
void  Date::show(){
    cout << year << '-' << month << '-'
				 << day << endl;
}



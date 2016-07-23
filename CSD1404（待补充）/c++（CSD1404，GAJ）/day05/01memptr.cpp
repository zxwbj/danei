#include <iostream>
using namespace std;
struct  Date{
    int  year;
		int  month;
		int  day;
};
int main(){
    Date  date={2014,10,1};
		/* 定义一个成员指针 指向month这个成员 
		   通过指针 取得date中 month 对应的值 */
		union{
    int   Date::*pm;
		int   *pi;
		};
		pm=&Date::month;
		cout << "pm month=" << pm << ":" << pi 
				 << endl;
    cout << date.*pm << endl;
		pm=&Date::year;
    cout << date.*pm << endl;
    cout << "pm year=" << pm << ":" << pi 
				 << endl;
    pm=&Date::day;
    cout << date.*pm << endl;
    cout << "pm day=" << pm << ":" << pi 
				 << endl;
}


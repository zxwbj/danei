#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>
using namespace std;
struct Date{
    int year;
		int month;
		int day;
		/* 重载Date的输出运算符 就可以使用 
		   ostringstream对象 把日期变成字符串 
		   Date  date={2014,10,1};
			 cout << date ; */ 
};
ostream&  operator<<(ostream& os,
				const Date& date){
    return  os << setfill('0') << setw(4) 
				<< date.year << '-' << setw(2)
				<< date.month << '-' << setw(2)
        << date.day;
}
int main(){
    string  name="tom";
		int     age=24;
		double  salary=5500;
    ostringstream  oss;
		oss << name << ' ' << age << ' ' 
				<< salary;
    string  mystr=oss.str();
		cout << mystr << endl;
    /* 2014-07-17 14:20:37log
		  把当前时间变成字符串 */
    time_t  t=time(NULL);
		struct tm *mytm=localtime(&t);
    ostringstream   oss2;
    oss2 << setfill('0')<< mytm->tm_year+1900
				<< '-' << setw(2) << mytm->tm_mon+1
				<< '-' << setw(2) << mytm->tm_mday
				<< ' ' << setw(2) << mytm->tm_hour
				<< ':' << setw(2) << mytm->tm_min
				<< ':' << setw(2) << mytm->tm_sec
				<< "log";
    const char* mycstr=oss2.str().c_str();
    cout << mycstr << endl;
    /* 思考如何把一个日期对象 变成字符串 */
		Date   date={2014,7,17};
		ostringstream   oss3;
    oss3 << date;
    cout << oss3.str() << endl;
    /* istringstream  */
    istringstream iss("tomtest 25 7000");
    iss >> name >> age >> salary;
		cout << name << endl;
		cout << age << endl;
		cout << salary << endl;
}


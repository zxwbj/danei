#include <iostream>
using namespace std;
class  Date{
		int  year;
		int  month;
		int  day;
    public:
		Date(){
		    cout << "Date()" << endl;
		}
};
class Emp{
    int  eno;
		double salary;
		Date   date;
		public:
    Emp(){
		    cout << "Emp()" << endl;
		}
		void  show(){
		    cout << eno << ":" << salary << endl;
		}
};
int main(){
    Emp  emp;
		emp.show();
}




#include <iostream>
#include <iomanip>
using namespace std;
class  Date{
    private:
		int  year;
		int  month;
		int  day;
		public:
		void  setDate(int y=2014,int m=1,int d=1){
		    year=y;
				month=m;
				day=d;
		}
		void  show(){
		    cout << setfill('0') << setw(4) 
						 << year << '-' << setw(2)
						 << month << '-' << setw(2)
						 << day << endl;
		}
};
int main(){
    Date  date;
		date.setDate();
		date.show();
    date.setDate(2020,1,1);
		date.show();
}


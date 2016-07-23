#include <iostream>
using namespace std;
/* 申请3个Date  结构体空间  */
struct Date{
    int year;
		int month;
		int day;
		void  show(){
		    cout << year << '-' << month << '-'
						 << day << endl; 
		}
};
int main(){
		/* 申请了5个整数的堆空间 */
    int  *parr = new int[5];
    // parr[0]=9;
    //*(parr+0)=9;
		// *parr++=9;
    parr[0]=9;
    parr[1]=5;
    parr[2]=2;
    parr[3]=7;
    parr[4]=0;
		for(int i=0;i<5;i++){
		    cout << parr[i] << " ";
		}
		cout << endl;
		delete[] parr;
    Date  *pd=new Date[3];
		pd[0].year=2014;
    pd[0].month=7;
		pd[0].day=7;
		pd[0].show();
		pd[1].show();
		pd[2].show();
    delete[] pd;
    char   data[100];
    int  *pai = new (data)int[25];
    cout << (void*)data << endl;
		cout << pai  << endl;
}



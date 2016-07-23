#include <iostream>
#include <iomanip>
#include <unistd.h>
using namespace std;
class  MyTime{
		private:
    int  hour;
		int  min;
		int  sec;
		public:
		void  setHour(int h){
		    hour=h;
		}
		/* 为访问私有数据 公开访问接口 */
    void  setTime(int h=0,int m=0,int s=0){
		    hour=h;
				min=m;
				sec=s;
		}
		void  run(){
		    while(1){
				    show();
						dida();
				}
		}
		private:
		void   show(){
		    cout << setfill('0') << setw(2) 
					<< hour << ':' << setw(2) 
					<< min << ':' << setw(2) 
					<< sec << '\r' << flush;
		}
    void   dida(){
		    sleep(1);
				if(60 == ++sec){
				    sec=0;
						if(60 == ++min){
						    min=0;
                if(24 == ++hour){
								    hour=0;
								}
						}
				}
		}
};
int main(){
    MyTime   mytime;//={11,17,37};
		//mytime.hour=11;
		/* 使用公开的接口 给成员变量赋值 */
		mytime.setTime(11,17,37);
   // mytime.show();
		//mytime.dida();
		//mytime.show();
		mytime.run();
}



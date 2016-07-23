#include <iostream>
#include <iomanip>
#include <unistd.h>
using namespace std;
struct  MyTime{
    int  hour;
		int  min;
		int  sec;
		void  run(){
		    while(1){
				    show();
						dida();
				}
		}
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
    MyTime   mytime={11,17,37};
    mytime.show();
		mytime.dida();
		mytime.show();
		mytime.run();
}



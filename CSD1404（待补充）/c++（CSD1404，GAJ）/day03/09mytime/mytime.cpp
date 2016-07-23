#include "mytime.h"		
#include <iostream>
#include <iomanip>
using namespace std;
void  show(){ 
    cout << "this is show()" << endl;
}
				
MyTime::MyTime(int hour,int min,
	  int sec):hour(hour),min(min),sec(sec){ 
		
}
void  MyTime::run(){ 
    while(1){
		    show();
        dida();
		}
}
void  MyTime::show(){ 
    cout << setfill('0') << setw(2) << hour 
				<< ':' << setw(2) << min << ':'
				<< setw(2) << sec << '\r' << flush;
}
void  MyTime::dida(){ 
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




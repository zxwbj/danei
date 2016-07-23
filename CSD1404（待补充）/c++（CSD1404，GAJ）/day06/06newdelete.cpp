#include <iostream>
#include <cstdlib>
using namespace std;
class Date{
    int year;
		int month;
		int day;
		public:
		Date(){  cout << "Date()" << endl;  }
		~Date(){ cout << "~Date()" << endl; }
static void*  operator new(size_t size){
		cout << "operator new " << size << endl;
    return  malloc(size);
}
};
int main(){
    Date *date=new Date();
}


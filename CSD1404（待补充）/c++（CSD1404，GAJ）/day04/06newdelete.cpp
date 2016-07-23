#include <iostream>
using namespace std;
struct Date{
    int  year;
		int  month;
		int  day;
		Date(){
		    cout << "Date()" << endl;
		}
		~Date(){
		    cout << "~Date()" << endl;
		}
};
class  Person{
    int  age;
		Date  date;
    public:
		Person(){ 
		    cout << "Person()" << endl;
		}
		~Person(){ 
		    cout << "~Person()" << endl;
		}
};
#include <cstdlib>
int main(){
    Person *p=static_cast<Person*>(
						malloc(sizeof(Person)));
    free(p);
		Person *p2=new Person();
    delete  p2;
}



#include <iostream>
using namespace std;
class Animal{
		public:
    string  name;
		int     age;
		public:
		void   show(){
		    cout << "animal  show()" << endl;
				cout << name << ":" << age << endl;
		}
};
class Dog:public Animal{
    int  type;
		public:
		void   fun(){
		    cout << "狗看家" << endl;
		}
};
/* 写一个Cat类  继承Animal  提供成员变量 
   int   color  还扩展一个功能 抓老鼠 */
class  Cat:public Animal{
    int   coclor;
		public:
		void  catfun(){
		    cout << "猫抓老鼠" << endl; 
		}
};
int main(){
    cout << sizeof(Dog) << endl;
    Dog   dog;
		dog.name="test";
		dog.age=12;
    dog.show();
		dog.fun();

		Cat  cat;
    cat.name="cat";
		cat.show();
		cat.catfun();
}


#include <iostream>
using namespace std;
class Animal{
    string name;
		int    age;
		public:
		Animal(string name="",int age=0)
			  :name(name),age(age){
		}
		void  show(){
		    cout << name << ":" << age << endl; 
		}
		/* 这就是纯虚函数 */
		virtual void  fun()=0; 
};
class Dog:public Animal{
   public:
	 Dog(string name="",int age=0)
			 :Animal(name,age){
	 }	
	 void  fun(){
	     cout << "dog fun" << endl;
	 }
};
int main(){
   // Animal  a("xiaoqiang",2);
    //a.show();
    Dog  dog("wangcai",3);
		dog.show();
		dog.fun();
}


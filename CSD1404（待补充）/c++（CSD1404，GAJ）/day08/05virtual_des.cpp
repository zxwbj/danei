#include <iostream>
using namespace std;
class Animal{
    public:
		Animal(){
		    cout << "Animal()" << endl;
		}		
		virtual ~Animal(){
		    cout << "~Animal()" << endl;
		}
		virtual  void fun(){  }
};
class Dog:public Animal{
    public:
		Dog(){
		    cout << "Dog()" << endl;
		}		
		~Dog(){
		    cout << "~Dog()" << endl;
		}
};
int main(){
    Animal *pa=new Dog();
    delete pa;
}


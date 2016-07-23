#include <iostream>
#include <typeinfo>
using namespace std;
class Animal{
    public:
		virtual void  show(){ 
				cout << "show()" << endl; 
		}		
};
class Dog:public Animal{
		public:
		void   dogfun(){
		    cout << "看家" << endl;
		}		
		void  show(){
		    cout << "dog show()" << endl;
		}
};
class Cat:public Animal{
    public:
		void  catfun(){
		    cout << "抓老鼠" << endl;
		}		
		void  show(){
		    cout << "cat show()" << endl;
		}
};
void  testAnimal(Animal* a){
    a->show();
    /* 判定指针指向的具体类型 */
		if(typeid(*a)==typeid(Dog)){
		     ((Dog*)a)->dogfun();
		}else if(typeid(*a)==typeid(Cat)){
		     ((Cat*)a)->catfun();
		}

}
int main(){
    int  *pi=new int(100);
		cout << typeid(pi).name() << endl;
		cout << typeid(*pi).name() << endl;
		Animal  *pa=new Cat();
    cout << typeid(pa).name() << endl;
    cout << typeid(*pa).name() << endl;
    if(typeid(*pa)==typeid(Dog)){
		    cout << "pa 指向Dog类型" << endl;
		}
		testAnimal(pa);
}


#include <iostream>
using namespace std;
class Animal{
    public:
		virtual void  show(){
				cout << "animal show()" << endl;
		}		
};
class Dog:public Animal{
		string name;
		public:
		void  show(){
		    cout << "dog show()" << endl;
		}
		void  dogfun(){
		    cout << "看家" << endl;
				cout << name << endl;
		}
};
class Cat:public Animal{
};
void  testAnimal(Animal* a){
    if(dynamic_cast<Cat*>(a)){
		    cout << "a 指向猫 " << endl;
		}
		/* 判定a是否Dog类型的对象 如果是 就
		   调用dogfun  */
		if(dynamic_cast<Dog*>(a)){
		    cout << "a指向狗" << endl;
				((Dog*)a)->dogfun();
		}
}
int main(){
    Animal  *pa=new Dog();
		testAnimal(pa);
		/* 需要经过判断才能转成相应的类型 */
		((Dog*)pa)->dogfun();
    
}

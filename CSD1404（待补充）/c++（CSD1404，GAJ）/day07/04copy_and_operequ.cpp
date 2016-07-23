#include <iostream>
using namespace std;
class Animal{
    public:
		Animal(){   }
		Animal(const Animal& a){
		    cout << "Animal(const Animal&)" 
						<< endl;
		}		
    Animal&  operator=(const Animal& a){
		    cout << "operator=(const Animal)"
						<< endl;
				return *this;
		}
};
class  Cat:public Animal{
    public:
	  Cat(){  }
	  /* 指定调用父类的拷贝构造函数 */	
		Cat(const Cat& cat):Animal(cat){
		    cout << "Cat(const Cat&)" << endl;
		}	
		Cat&  operator=(const Cat& cat){
				/* 使用类名:: 区分 */
				Animal::operator=(cat);
		    cout << "operator=(Cat&)" << endl;
				return *this;
		}
};
int main(){
    Cat  cat;
		Cat  cat2;//=cat;
		cat2=cat;
}




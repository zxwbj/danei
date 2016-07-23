#include <iostream>
using namespace std;
class Animal{
    public:
		void   show(){
		    cout << "show()" << endl;
		}		
		virtual void run(){
		    cout << "动物run()" << endl;
		}
};
class Dog:public Animal{
    public:
	  /* 函数重写 */			
    void  run(){
		    cout << "狗用四条腿跑" << endl;
		}
		/* dog 的个性 */
		void  dogfun(){
		    cout << "狗的作用是看家" << endl;
		}
};
class Fish:public Animal{
    public:
		void  run(){
		    cout << "鱼使用鳍在水中游" << endl;
		}		
};
class Bird:public Animal{
    public:
		/*void  run(){
		    cout << "鸟用翅膀飞" << endl;
		}	*/
		void  show(){
		    cout << "bird show()" << endl;
		}
};
/* 类型通用  损失个性  */
void   testAnimal(Animal&  a){
    a.run();
		// 恢复个性 
}
Animal*  getA(int x){
    if(0==x){
		   return  new  Dog();
		}else if(1==x){
		   return  new Fish();
		}else{
		   return  new Bird();
		}
}
int main(){
    Dog  dog;
		Fish  fish;
		Bird  bird;
    testAnimal(dog);
    testAnimal(fish);
    testAnimal(bird);
		Animal  *a=getA(0);
    a->run();
    Animal *aa=getA(2);
		aa->run();
}





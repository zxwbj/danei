#include <iostream>
using namespace std;
class Animal{
		//int  *pi;
    public:
		virtual void   show(){  
		    cout << "animal show" << endl;
		}		
		virtual void  fun(){
		    cout << "animal fun" << endl;
		}
};
/* 写一个Dog类 继承Animal  取得Dog类型 
  对应的虚函数表地址 观察和Animal的不同 */
class Dog:public Animal{  
    public:
				void  fun(){
				    cout << "看家" << endl;
				}
};
class Cat:public Animal{
    public:
				void  fun(){
				    cout << "抓老鼠" << endl;
				}
};
// #include <cstring>
extern "C" void  memcpy(void* des,void *src,size_t size);
int main(){
    cout << sizeof(Animal) << endl;
    Animal  a;
		Animal  b;
    int *p=reinterpret_cast<int*>(&a);
		cout << hex << *p << endl;
    p=reinterpret_cast<int*>(&b);
		cout << hex << *p << endl;
		Dog   dog;
		Cat   cat;
		/* 内存复制 */
		memcpy(&dog,&cat,4);
		Animal *pdog=&dog;
		pdog->fun();
    p=reinterpret_cast<int*>(&dog);
		cout << hex << *p << endl;

}




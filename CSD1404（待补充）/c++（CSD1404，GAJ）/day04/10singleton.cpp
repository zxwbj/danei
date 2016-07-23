#include <iostream>
using namespace std;
class Singleton{
    private:
		Singleton(){  }
		Singleton(const Singleton& s){ }
		static  Singleton sig;
		public:
    static Singleton& getInstance(){
		    return  sig;
		}
};
/* 这叫饿汉式  提前创建好对象 */
Singleton   Singleton::sig;
int main(){
    Singleton&  sig=Singleton::getInstance();
    Singleton&  sig2=Singleton::getInstance();
    Singleton&  sig3=Singleton::getInstance();
    cout << &sig << endl;
    cout << &sig2 << endl;
    cout << &sig3 << endl;
}



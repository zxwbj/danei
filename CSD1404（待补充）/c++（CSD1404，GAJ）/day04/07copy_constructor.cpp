#include <iostream>
using namespace std;
class  Person{
    string  name;
		int     age;
		public:
		Person(string name="",int age=0)
				:name(name),age(age){
				cout << "Person()" << endl;		
		}
		void  show()const{
		    cout << name << ":" << age << endl;
		}
		/* 写一个拷贝构造函数 */
    Person(const Person& p){
	      cout << "Person(Person)" << endl;	
				name=p.name;
				age=p.age;
		}
};
void  showPerson(const Person& p){
   p.show(); 
}
const Person&  getPerson(const Person& p){
    return  p;
}
Person  getP(){
   /* Person  p;
		return  p;*/
		/* 匿名对象简化编程  编译器会优化 只有一次
		   构造 */
		return Person("zs",25);
}
int main(){
    const Person  pa("zhourunfa",55);
		Person  pb=pa;
    pb.show();
		showPerson(pb);
		showPerson(pa);
	  getPerson(pa);
		cout << "---------" << endl;
		getP();
}



#include <iostream>
#include <string>
using namespace std;
struct  Student{
		/* 特征 */
    string  name;
    int     age;
		string  sno;
		bool    gender;
		double  height;
		double  weight;
    /* 行为 */
    void   play(string name){
		    cout << "play " << name << endl;
		}
    void   learn(string name){
		    cout << "learn " << name << endl;
		}
		void   show(){
		    cout << "my name is " << name 
						 << "age is " << age << endl; 
		}
};
int main(){
    Student   sa={"libingbing",30,"sn000123",
		    false,1.67,95};
    sa.play("war3");
		sa.learn("c++");
    sa.show();
}





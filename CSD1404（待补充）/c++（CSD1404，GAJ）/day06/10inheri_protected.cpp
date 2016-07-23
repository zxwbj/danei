#include <iostream>
using namespace std;
class A{
    private:
		void  showa(){
		    cout << "A private" << endl;
		}		
		protected:
		void  showb(){
		    cout << "A protected" << endl;
		}
		public:
    void  showc(){
				showa();
		    cout << "A public " << endl;
		}
};
class B:protected A{   
		public:
		void  show(){
	      showc();
				showb();
		}
};
int main(){
    B   b;
		b.show();
}







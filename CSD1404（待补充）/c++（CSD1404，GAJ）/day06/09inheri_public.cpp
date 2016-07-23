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
		    cout << "A public " << endl;
		}
		protected:
		void  showp(){
		    showa();
		}
};
class B:public A{   
    public:
		void  show(){
		    showb();
				//showa();
        showp();
		}		
};
int main(){
    B   b;
		b.showc();
		//b.showb();
		b.show();
}







#include <iostream>
using namespace std;
class Array{
    int  cap;
		int  size;
		int  *data;
		public:
		Array(int cap=5):cap(cap),size(0){
		    data=new int[cap];
		}
		~Array(){
		    delete[]  data;
				data=NULL;
		}
    /* 写一个拷贝构造函数 */
    Array(const Array& arr){
		    cout << "Array(const Array&)" << endl;
				cap=arr.cap;
				size=arr.size;
        data=new int[cap];
				for(int i=0;i<size;i++){
				    data[i]=arr.data[i];
				} 
		}
};
int  main(){
    //Array   arra;
		Array   arrb(10);
    Array   arrc;
		arrc=arrb;
}





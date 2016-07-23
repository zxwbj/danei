#include <iostream>
using namespace std;
class Array{
		/* 最大容量 */
		int  cap;
		/* 有多少个元素 */
		int  size;
		/* 真正存储数据的区域 */
    int  *data;
    public:
		Array(int cap=5):cap(cap),size(0){
		    data=new int[cap]; 
		}
		~Array(){
		    delete[]  data;
		}
		Array(const Array& a){
		    cap=a.cap;
				size=a.size;
				/* 重新申请内存空间 */
				data=new int[cap];
				/* 复制数据 */
				for(int i=0;i<size;i++){
				    data[i]=a.data[i];
				}
		}
};
int main(){
    Array  arra;
		Array  arrb=arra;
}




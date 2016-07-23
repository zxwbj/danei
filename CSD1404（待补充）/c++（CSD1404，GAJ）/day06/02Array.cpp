#include <iostream>
using namespace std;
class Array{
    int  cap;
		int  size;
		int  *data;
		public:
		/* 防止默认单参转换 */
		explicit Array(int cap=5):cap(cap),size(0){
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
		/* 赋值运算符函数 */
    Array&   operator=(const Array& arr){
				// 防止自赋值 
				if(this!=&arr){
		    cap=arr.cap;
				size=arr.size;
				int *temp=data;
				/* 重新申请内存 */
				data=new int[cap];
        /* 复制数据 */
        for(int i=0;i<size;i++){
				    data[i]=arr.data[i];
				}
				/* 释放原来的内存 */
				delete[]  temp;
				}
        return *this;
		}
		/* 思考[] 运算符的实现 */
    int   operator[](int ind){
				 if(ind>=size){
				     throw "小伙 下标不正确";
				 }
		     return data[ind];
		}
    /* 设计一个函数 负责插入数据 */
		void   push_back(int d){
		    /* 能放入就放入 不能就扩容 */ 
		    if(size>=cap){
				    // 扩容
						expend();
				}
				data[size++]=d;
		}
    /* 把cap*2+1 处理内存中的数据 */
    void   expend(){
		    cap=cap*2+1;
				int  *temp=data;
				data=new int[cap];
        /* 复制原来的数据  释放原来的内存 */
        for(int i=0;i<size;i++){
				    data[i]=temp[i];
				}
        delete[] temp;
		}
		friend  ostream&  operator<<(ostream& os,
				 const Array& arr){
		    cout << "[ "; 
				for(int i=0;i<arr.size-1;i++){
				    cout << arr.data[i] << ","; 
				}
				if(arr.size!=0){
				cout << arr.data[arr.size-1];
				}
				cout << " ]";
				return  os;
		}
};
int  main(){
    //Array   arra;
		Array   arrb(3);
		//arrb=arrb;
		arrb.push_back(9);
		arrb.push_back(5);
		arrb.push_back(2);
		arrb.push_back(7);
		arrb.push_back(9);
		cout << arrb << endl;
    Array   arrc=arrb;
		cout << arrc << endl;
		/* 默认调用系统提供的运算符函数 
		Array&  operator=(const Array& arr) */
	  arrc=arrb;
		cout << arrc << endl;
		try{
		cout << arrc[3] << endl;
		cout << arrc[2] << endl;
		//cout << arrc[10] << endl;
		cout << arrc[100000] << endl;
		}catch(const char* msg){
		cout << msg << endl;   
		}
    cout << "app continue" << endl;
		/* 单参构造机制 */
		//Array  arrd=100;
		Array  arrd(100);

}




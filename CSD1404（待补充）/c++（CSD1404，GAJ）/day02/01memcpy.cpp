#include <iostream>
// #include <cstring>
using namespace std;
/* 按照c语言编译器的方式 生成调用名 */
extern "C" 
void*  memcpy(void* desc,void* src,
				size_t size);
int main(){
    int  x=100;
		int  y=99;
		/* c的库函数 memcpy(void* desc,void src,
			 size_t size) */
		memcpy(&y,&x,4);
		cout << "y=" << y << endl;
}


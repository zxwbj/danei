#include <iostream>
#include <fstream>
using namespace std;
int main(){
    int  x;
    ifstream  ifs("03stdio.cpp");
		/* 要求读取文件 把文件的内容大印屏幕上 */
		//while(1){
		    x=cin.get();
				cout.put(x);
				cout << x << endl;
	//	}
			
	  while((x=ifs.get())!=EOF){ 	 		
		   cout.put(x);
		}
		char  c;
		ifs.close();
		ifs.open("03stdio.cpp");
		while(ifs.get(c)){
		   cout.put(c);
		}
		ifs.close();

}




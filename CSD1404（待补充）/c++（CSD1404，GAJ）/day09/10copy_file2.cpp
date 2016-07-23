#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
int main(){
    ifstream  ifs("01vtable.cpp",
						ios::binary|ios::in);
		if(!ifs){
		     perror("open file failed");
				 return -1;
		}
		char  data[100];
		ofstream  ofs("cp01vtable.cpp");
		if(!ofs){
		    perror("create file failed");
				return  -2;
		}
		while(ifs.read(data,100)){
		    ofs.write(data,100);
		}
		int  datacount=ifs.gcount();
    ofs.write(data,datacount);
		ifs.close();
		ofs.close();
		/*ifs.read(data,400);
		cout << ifs.gcount() << endl;
		cout  << ifs << endl;
		ifs.read(data,400);
		cout << ifs.gcount() << endl;
		cout << ifs << endl; */


}


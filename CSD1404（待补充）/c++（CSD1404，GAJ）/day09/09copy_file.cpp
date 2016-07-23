#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream  ifs("01vtable.cpp");
		if(!ifs){
		    cout << "打开文件失败" << endl;
				return  -1;
		}
		ofstream  ofs("cp01vtable.cpp");
    if(!ofs){
		    cout << "创建文件失败" << endl;
				return  -2;
		}
		char  c;
    while(ifs.get(c)){
		    ofs.put(c);
		}
    ifs.close();
		ofs.close();
}



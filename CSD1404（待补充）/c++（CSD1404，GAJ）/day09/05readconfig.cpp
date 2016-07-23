#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream  ifs("config.txt");
		if(!ifs){
		   cout << "打开文件失败" << endl; 
			 return  -1;
		}
    char  temp[200];
		char  ip[20];
    //char  port[20];
		short  port;
		char  name[30];
    ifs.getline(temp,199,'=');
		ifs.getline(ip,20);
    ifs.getline(temp,199,'=');
		//ifs.getline(port,20);
		/* 这是格式输入 */
		ifs >> port;
    ifs.getline(temp,199,'=');
		ifs.getline(name,30);
    cout << ip << ":" << port << ':' 
				 << name << endl;
}




#include <iostream>
#include <fstream>
using namespace std;
int main(){
    fstream  iofs("rand.txt");
		if(!iofs){
		    cout << "open file failed" << endl;
				return -1;
		} 
		cout << iofs.tellp() << endl;
		cout << iofs.tellg() << endl;
		iofs.seekg(0,ios::end);
		cout << iofs.tellp() << endl;
		cout << iofs.tellg() << endl;
    iofs.seekg(-25,ios::end);    
		cout << iofs.tellp() << endl;
		cout << iofs.tellg() << endl;
		string  mystr;
    iofs >> mystr ;
		cout << mystr << endl;
		cout << iofs.tellp() << endl;
		cout << iofs.tellg() << endl;
    /* 当前位置 向前调3 然后读取一个整数 */
    iofs.seekg(-3,ios::cur);
		int   x;
		iofs >> x ;
		cout << x << endl;
		iofs << '#';
		iofs << 12345;

}


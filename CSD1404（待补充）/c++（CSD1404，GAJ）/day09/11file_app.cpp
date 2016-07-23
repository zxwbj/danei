#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ofstream  ofs("data.dat");
		if(!ofs){
		    cout << "open file failed" << endl;
				return -1;
		}
		for(int i=1;i<100;i++){
				ofs.close();
				ofs.open("data.dat",ios::app);
		    ofs << i << '\n';
		}
		ofs.close();

}



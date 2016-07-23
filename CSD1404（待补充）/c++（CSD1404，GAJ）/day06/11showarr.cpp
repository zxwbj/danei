#include <iostream>
using namespace std;
/*
void  showArr(int (&rdata)[5]){
    int count=sizeof(rdata)/sizeof(rdata[0]);
		cout << count << endl;
		for(int i=0;i<count;i++){
		    cout << rdata[i] << " ";
		}
		cout << endl;
}*/
/* 这是模版 */
template<typename T>
void  showArr(T& rdata){
    int count=sizeof(rdata)/sizeof(rdata[0]);
		for(int i=0;i<count;i++){
		    cout << rdata[i] << " ";
		}
		cout << endl;
}
int main(){
    int  data[5]={9,5,2,7,1};
		showArr(data);
    int   data2[3]={1,2,3};
    showArr(data2);
}


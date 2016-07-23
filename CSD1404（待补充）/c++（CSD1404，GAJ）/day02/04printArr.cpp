#include <iostream>
using namespace std;
void  printArr(int *data,int size=1,
		char sep=',' );
int main(){
    int  data[5]={9,5,2,7,0};
		printArr(data);
		printArr(data,5);
		printArr(data,3);
		printArr(data,5,'$');
}
void  printArr(int *data,int size,char sep){
    cout << "[ ";
		for(int i=0;i<size-1;i++){
		    cout << data[i] << sep;
		}
		cout << data[size-1] << " ]" << endl;
}


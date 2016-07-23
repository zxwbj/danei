#include <iostream>
#include "dmsexception.h"
#include <ctime>
#include <cstdlib>
using namespace std;
void   initNetWork()
		throw(DmsInitNetWorkException){
    int temp=rand()%3;
    if(0==temp){
		    cout << "初始化网络成功" << endl;
		}else if(1==temp){
		    throw DmsInitNetWorkException
						("init socket failed");
		}else{
		    throw DmsInitNetWorkException
						("connect server failed");
		}
}
void  sendData()
		throw(DmsInitNetWorkException,
					DmsSendDataException){
		try{
        initNetWork();
		}catch(DmsInitNetWorkException& e){
				/* 可以选择在这一层进行处理 
				   也可以继续上抛 */
		    throw ;
		}
    while(1){
		    int  temp=rand()%2;
				if(0==temp){
				    cout << "send data to server success" << endl;
				}else{
				     throw DmsSendDataException
						 ("send data to server failed");
				}
		} 
}

int main(){
    srand(time(NULL));
		try{
		sendData();
		}catch(DmsInitNetWorkException& e){
		cout << e.what() << endl;
		cout << "对数据进行追加处理" << endl;
		}catch(DmsSendDataException& e){
		cout << e.what() << endl;
		cout << "尝试连接三次 连接备用服务器"
				 << endl;
		}
		cout << "app continue" << endl;
}




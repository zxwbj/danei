/* 异常定义的头文件 */
#ifndef  DMSEXCEPTION_H
#define  DMSEXCEPTION_H
#include <string>
using namespace std;
class   DmsException{
    string   msg;
		public:
	  DmsException(string msg="dms exception")
		:msg(msg){
		}	
    const  char *  what()const throw(){
		    return  msg.c_str(); 
		}
}; 
class  DmsClientException:public DmsException{
    public:
		DmsClientException(string msg=
				"dms client exception"):
				DmsException(msg){
		
		}		
};
/* 初始化网络异常 */
class DmsInitNetWorkException:
		public DmsClientException{
    public:
    DmsInitNetWorkException(string msg="")
				:DmsClientException(msg){
		}
};
/* 发送数据异常 */
class DmsSendDataException:
		public DmsClientException{
    public:
		DmsSendDataException(string msg="")
				:DmsClientException(msg){
		}		
};
#endif


#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <fstream>
using namespace std;
/* 对数据进行异或操作 */
void   _xor(const char *src,const char* des,
		unsigned char key){
    ifstream   ifs(src);
		if(!ifs){
		    cout << "打开源文件失败" << endl;
				return ;
		}
    ofstream   ofs(des);
		if(!ofs){
		    cout << "创建目标文件失败" << endl;
				return ;
		}
		char   data[100];
    while(ifs.read(data,100)){
		    for(int i=0;i<100;i++){
				    data[i]^=key;
				}
				ofs.write(data,100);
		}
    int  datacount=ifs.gcount();
    for(int i=0;i<datacount;i++){
		    data[i]=data[i]^key;
		}
		ofs.write(data,datacount);
		ofs.close();
		ifs.close();
}
/* 加密函数 */
void  encode(const char* src,const char *des){
    unsigned char key=rand()%256;
		_xor(src,des,key);
		cout << "key=" << (int)key << endl;
}
/* 解密函数 */
void  decode(const char* src,const char* des,
		unsigned char key){
    _xor(src,des,key);
}
int main(int argc,char** argv){
		srand(time(NULL));
    if(argc<3){
		    cout << "程序使用错误 如下使用:" << endl;
				cout << "加密: a.out  源文件名 加密文件名 " 
						 <<  endl;
				cout << "解密: a.out  加密文件名  解密文件名 密钥 " << endl;
				return  -1;
		}else if(3==argc){
		    cout << " 加密文件 密钥随机生成 " << endl;
				encode(argv[1],argv[2]);
		}else{
		    cout << " 解密文件 "  << endl;
				decode(argv[1],argv[2],atoi(argv[3]));
		}
}


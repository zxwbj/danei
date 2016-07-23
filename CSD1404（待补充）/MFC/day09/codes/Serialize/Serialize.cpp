// Serialize.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Serialize.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

// 1 写数据(存储)
void Store()
{
   CFile file;
   //1 新建文件
   file.Open("c:\\serial.dat",
	   CFile::modeCreate|CFile::modeWrite);
   //2 写入数据
   //2.1 定义CArchive对象
   CArchive ar(&file,CArchive::store);
   //2.2 写数据
   ar<<100<<12.25<<'A';
   //2.3 关闭CArchive对象
   ar.Close();
   //3 关闭文件
   file.Close();
}
// 2 读数据(加载)
void Load()
{
    CFile file;
	file.Open("c:\\serial.dat",CFile::modeRead);
	CArchive ar(&file,CArchive::load);
	int nValue=0;
	double fValue=0.0;
	char cValue;
	ar>>nValue>>fValue>>cValue;
	ar.Close();
	file.Close();
	//输出数据
	printf("nValue=%d\n",nValue);
	printf("fValue=%f\n",fValue);
	printf("cValue=%c\n",cValue);

}	
int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
    //Store();
	Load();
 
	return 0;
}



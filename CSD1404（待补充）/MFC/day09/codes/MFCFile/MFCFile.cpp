// MFCFile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MFCFile.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;
//文件属性的获取和设置
void FileStatus()
{
    //1 获取文件属性
	CFileStatus status;
	CFile::GetStatus("c:\\mfc.txt",status);
	//2 定义一个时间段变量(7天)
	CTimeSpan span(7,0,0,0);
	//3 基于文件的创建时间提前一周
    status.m_ctime-=span;
	//4 设置文件属性
	CFile::SetStatus("c:\\mfc.txt",status);

}
//文件查找操作
void FileFind(CString sPath)
{
   //1 开始查找
	CFileFind find;
	BOOL bRet=find.FindFile(sPath+"\\*.*");
	while (bRet)
	{
		//2 查找下一个
		bRet=find.FindNextFile();
		//3 获取文件名称
		//CString sName=find.GetFileName();
		sPath=find.GetFilePath();
		if (!find.IsDots())//排除.目录
		{
			if (find.IsDirectory())
			{
				printf("目录:%s\n",sPath);
				FileFind(sPath);//递归
			}
			else
			{
				printf("文件:%s\n",sPath);
			}
		}
		
	}
	//4 结束查找
	find.Close();


}
int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	FileFind("e:\\mfc");
    //FileStatus();
	return 0;
}



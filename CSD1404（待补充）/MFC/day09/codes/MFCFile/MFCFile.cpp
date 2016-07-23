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
//�ļ����ԵĻ�ȡ������
void FileStatus()
{
    //1 ��ȡ�ļ�����
	CFileStatus status;
	CFile::GetStatus("c:\\mfc.txt",status);
	//2 ����һ��ʱ��α���(7��)
	CTimeSpan span(7,0,0,0);
	//3 �����ļ��Ĵ���ʱ����ǰһ��
    status.m_ctime-=span;
	//4 �����ļ�����
	CFile::SetStatus("c:\\mfc.txt",status);

}
//�ļ����Ҳ���
void FileFind(CString sPath)
{
   //1 ��ʼ����
	CFileFind find;
	BOOL bRet=find.FindFile(sPath+"\\*.*");
	while (bRet)
	{
		//2 ������һ��
		bRet=find.FindNextFile();
		//3 ��ȡ�ļ�����
		//CString sName=find.GetFileName();
		sPath=find.GetFilePath();
		if (!find.IsDots())//�ų�.Ŀ¼
		{
			if (find.IsDirectory())
			{
				printf("Ŀ¼:%s\n",sPath);
				FileFind(sPath);//�ݹ�
			}
			else
			{
				printf("�ļ�:%s\n",sPath);
			}
		}
		
	}
	//4 ��������
	find.Close();


}
int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	FileFind("e:\\mfc");
    //FileStatus();
	return 0;
}



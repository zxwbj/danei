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

// 1 д����(�洢)
void Store()
{
   CFile file;
   //1 �½��ļ�
   file.Open("c:\\serial.dat",
	   CFile::modeCreate|CFile::modeWrite);
   //2 д������
   //2.1 ����CArchive����
   CArchive ar(&file,CArchive::store);
   //2.2 д����
   ar<<100<<12.25<<'A';
   //2.3 �ر�CArchive����
   ar.Close();
   //3 �ر��ļ�
   file.Close();
}
// 2 ������(����)
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
	//�������
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



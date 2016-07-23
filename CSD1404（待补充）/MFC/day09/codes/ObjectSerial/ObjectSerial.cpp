// ObjectSerial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ObjectSerial.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

//2 ����֧�����л�����
class CAddress:public CObject
{
public:
	CAddress(){}
	CAddress(CString sProvince,CString sCity)
	{
       m_sProvince=sProvince;
       m_sCity=sCity;
	}
	CAddress(const CAddress& a)
	{
       m_sProvince=a.m_sProvince;
       m_sCity=a.m_sCity; 
	}

	void Show()
	{
		printf("��ַ:%sʡ%s��",m_sProvince,m_sCity);
	}
    virtual	 void Serialize(CArchive& ar)
	{
	  if (ar.IsStoring())
	  {
		  ar<<m_sProvince<<m_sCity;
	  } 
	  else
	  {
		  ar>>m_sProvince>>m_sCity;
	  }
	}
private:
	CString m_sProvince;
	CString m_sCity;
	DECLARE_SERIAL(CAddress)
};
IMPLEMENT_SERIAL(CAddress,CObject,1)




//1 ����֧�����л�����
class CStudent:public CObject
{
public:
	CStudent(){}
	CStudent(CString sName,int nAge):m_sName(sName),m_nAge(nAge){}
	CStudent(CString sName,int nAge,
		CAddress address):m_sName(sName),
		m_nAge(nAge),m_address(address){}
	

	void Show()
	{
		printf("����:%s\n",m_sName);
		printf("����:%d\n",m_nAge);
		m_address.Show();
	}
	virtual void Serialize( CArchive& ar )
	{
		CObject::Serialize(ar);
		m_address.Serialize(ar);
        if (ar.IsStoring())
        {
			ar<<m_sName<<m_nAge;
        }
		else
		{
			ar>>m_sName>>m_nAge;
		}
	}
private:
	CString m_sName;
	int m_nAge;
	CAddress m_address;
	//���л���������
	//DECLARE_SERIAL(CStudent)
	_DECLARE_DYNCREATE(CStudent) 
	AFX_API friend CArchive& AFXAPI 
	operator>>(CArchive& ar, CStudent* &pOb);
};
//���л���ʵ�ֺ�
//IMPLEMENT_SERIAL(CStudent,CObject,1)

CObject* PASCAL CStudent::CreateObject() 
{ 
	return new CStudent; 
} 
_IMPLEMENT_RUNTIMECLASS(CStudent, CObject, 1, 
						CStudent::CreateObject)
						
AFX_CLASSINIT _init_CStudent(RUNTIME_CLASS(CStudent)); 

CArchive& AFXAPI operator>>(CArchive& ar, CStudent* &pOb) 
{ 
	pOb = (CStudent*) ar.ReadObject(RUNTIME_CLASS(CStudent)); 
			return ar; 
} 
//2 д����
void ObjectStore(CStudent *pStu)
{
    CFile file;
	file.Open("c:\\stu.bin",
		CFile::modeCreate|CFile::modeWrite);
	CArchive ar(&file,CArchive::store);
	ar<<pStu;
	ar.Close();
	file.Close();
}
//������
void ObjectLoad()
{
	CFile file;
	file.Open("c:\\stu.bin",CFile::modeRead);
	CArchive ar(&file,CArchive::load);
	CStudent *pStu=NULL;
	ar>>pStu;
	ar.Close();
	file.Close();
	//���
	if (pStu)
	{
		pStu->Show();
		delete pStu;
		pStu=NULL;
	}
}
int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	CAddress address("�ӱ�","����");
	CStudent student("�ŷ�",30,address);
    ObjectStore(&student);
	ObjectLoad();
	return 0;
}



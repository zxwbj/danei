// AdoDatabase.cpp: implementation of the CAdoDatabase class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TestAdo.h"
#include "AdoDatabase.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAdoDatabase::CAdoDatabase()
{

}

CAdoDatabase::~CAdoDatabase()
{
    Close();
}
BOOL CAdoDatabase::OpenMDB(CString sPath)
{
    //创建Connection对象
	HRESULT nRet=
		m_pConn.CreateInstance(__uuidof(Connection));
    if (FAILED(nRet))
    {
		return FALSE;
    }
	CString strConn;
	strConn.Format("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s",sPath);
	//连接数据库
	nRet=m_pConn->Open(_bstr_t(strConn),"","",-1);
	if (FAILED(nRet))
	{
		return FALSE;
	}
	return TRUE;
}
void CAdoDatabase::Close()
{
	m_pConn->Close();
}

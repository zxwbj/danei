// AdoDatabase.h: interface for the CAdoDatabase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADODATABASE_H__756737F1_C7B1_46C2_87C5_4AB8031A32E2__INCLUDED_)
#define AFX_ADODATABASE_H__756737F1_C7B1_46C2_87C5_4AB8031A32E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAdoDatabase  
{
public:
	CAdoDatabase();
	virtual ~CAdoDatabase();
	// 1 连接数据库
	BOOL OpenMDB(CString sPath);
	// 2 关闭数据库
	void Close();
	// 3 执行Sql语句
	void OpenSql(CString strSql);
	// 4 启动事务
	void BeginTrans(); 
	// 5 结束事务
	void EndTrans(BOOL bCommit=TRUE);
public:
	_ConnectionPtr m_pConn;
};

#endif // !defined(AFX_ADODATABASE_H__756737F1_C7B1_46C2_87C5_4AB8031A32E2__INCLUDED_)

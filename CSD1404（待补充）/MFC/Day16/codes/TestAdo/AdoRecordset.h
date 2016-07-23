// AdoRecordset.h: interface for the CAdoRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADORECORDSET_H__A2A73FC4_CFDD_44CC_B736_9A983491DC68__INCLUDED_)
#define AFX_ADORECORDSET_H__A2A73FC4_CFDD_44CC_B736_9A983491DC68__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AdoDatabase.h"
class CAdoRecordset  
{
public:
	CAdoRecordset();
	virtual ~CAdoRecordset();
	// 1 打开表
	BOOL OpenTable(CString sTable,CAdoDatabase *pDB);
    // 执行Sql语句
	BOOL OpenSql(CString sSql,CAdoDatabase *pDB);
	// 2 获取表中字段的数量
	long GetFieldCount();
	// 3 获取字段的标题
	void GetFieldName(long nIndex,CString& sName);
    // 4 设置/获取字段的值
	void SetFieldValue(long nIndex,CString sValue);
    void GetFieldValue(long nIndex,CString& sValue);
	// 5 记录集的指针操作
	void MoveFirst();
	void MoveLast();
	void MoveNext();
	void MovePrevious();
	void Move(long nNums);
	BOOL IsEOF();
	BOOL IsBOF();
	// 6 添加新的记录
	void AddNew();
	// 7 更新到数据库
	void Update();
	// 8 删除当前记录
	void Delete();

public:
	_RecordsetPtr m_pSet;
};

#endif // !defined(AFX_ADORECORDSET_H__A2A73FC4_CFDD_44CC_B736_9A983491DC68__INCLUDED_)

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
	// 1 �򿪱�
	BOOL OpenTable(CString sTable,CAdoDatabase *pDB);
    // 2 ��ȡ�����ֶε�����
	long GetFieldCount();
	// 3 ��ȡ�ֶεı���
	void GetFieldName(long nIndex,CString& sName);
    // 4 ����/��ȡ�ֶε�ֵ
	void SetFieldValue(long nIndex,CString sValue);
    void GetFieldValue(long nIndex,CString& sValue);
	// 5 ��¼����ָ�����
	void MoveFirst();
	void MoveLast();
	void MoveNext();
	void MovePrevious();
	void Move(long nNums);
	BOOL IsEOF();
	BOOL IsBOF();

public:
	_RecordsetPtr m_pSet;
};

#endif // !defined(AFX_ADORECORDSET_H__A2A73FC4_CFDD_44CC_B736_9A983491DC68__INCLUDED_)

// TestAdoDlg.h : header file
//

#if !defined(AFX_TESTADODLG_H__E2694113_8277_4CE4_81B5_249850FDD32B__INCLUDED_)
#define AFX_TESTADODLG_H__E2694113_8277_4CE4_81B5_249850FDD32B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestAdoDlg dialog
#include "AdoDatabase.h"
#include "AdoRecordset.h"
class CTestAdoDlg : public CDialog
{
// Construction
public:
	void Show(CAdoRecordset *pSet);
	CTestAdoDlg(CWnd* pParent = NULL);	// standard constructor
    CAdoDatabase m_db;//���ݿ���� 
// Dialog Data
	//{{AFX_DATA(CTestAdoDlg)
	enum { IDD = IDD_TESTADO_DIALOG };
	CListCtrl	m_wndList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestAdoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestAdoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpenDb();
	afx_msg void OnOpenTable();
	afx_msg void OnAdd();
	afx_msg void OnDel();
	afx_msg void OnEdit();
	afx_msg void OnSql();
	afx_msg void OnTrans();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTADODLG_H__E2694113_8277_4CE4_81B5_249850FDD32B__INCLUDED_)

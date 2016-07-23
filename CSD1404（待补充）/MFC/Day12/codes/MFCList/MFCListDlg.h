// MFCListDlg.h : header file
//

#if !defined(AFX_MFCLISTDLG_H__C4F3EDC8_8093_4255_8EA6_C31303137EA7__INCLUDED_)
#define AFX_MFCLISTDLG_H__C4F3EDC8_8093_4255_8EA6_C31303137EA7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFCListDlg dialog

class CMFCListDlg : public CDialog
{
// Construction
public:
	CMFCListDlg(CWnd* pParent = NULL);	// standard constructor
    CImageList m_ilNormal;//图标列表
	CImageList m_ilSmall;//小图标列表
	CStringList m_lstPath;//路径的链表
// Dialog Data
	//{{AFX_DATA(CMFCListDlg)
	enum { IDD = IDD_MFCLIST_DIALOG };
	CListCtrl	m_wndList;
	CComboBox	m_wndStyle;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCListDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFCListDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeStyle();
	afx_msg void OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ShowData(CString sPath);
	void InitListCtrl();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCLISTDLG_H__C4F3EDC8_8093_4255_8EA6_C31303137EA7__INCLUDED_)

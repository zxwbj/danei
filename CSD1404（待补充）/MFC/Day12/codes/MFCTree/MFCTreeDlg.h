// MFCTreeDlg.h : header file
//

#if !defined(AFX_MFCTREEDLG_H__B90C44F6_0F51_4620_A894_46BD9A4604D6__INCLUDED_)
#define AFX_MFCTREEDLG_H__B90C44F6_0F51_4620_A894_46BD9A4604D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFCTreeDlg dialog

class CMFCTreeDlg : public CDialog
{
// Construction
public:
	void InitTreeCtrl();
	CMFCTreeDlg(CWnd* pParent = NULL);	// standard constructor
    CImageList m_ilNormal;//���ؼ���ͼ���б�
// Dialog Data
	//{{AFX_DATA(CMFCTreeDlg)
	enum { IDD = IDD_MFCTREE_DIALOG };
	CTreeCtrl	m_wndTree;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCTreeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFCTreeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCTREEDLG_H__B90C44F6_0F51_4620_A894_46BD9A4604D6__INCLUDED_)

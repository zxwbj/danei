#if !defined(AFX_DLGMODELESS_H__0A48CBFE_8A1E_4EC4_8AFA_0BBD6BDDA812__INCLUDED_)
#define AFX_DLGMODELESS_H__0A48CBFE_8A1E_4EC4_8AFA_0BBD6BDDA812__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgModeless.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgModeless dialog

class CDlgModeless : public CDialog
{
// Construction
public:
	CDlgModeless(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgModeless)
	enum { IDD = IDD_DIALOG2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgModeless)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgModeless)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMODELESS_H__0A48CBFE_8A1E_4EC4_8AFA_0BBD6BDDA812__INCLUDED_)

// MFCSdiWizard.h : main header file for the MFCSDIWIZARD application
//

#if !defined(AFX_MFCSDIWIZARD_H__94642331_1906_4CDB_BEC1_D98E02A52A6A__INCLUDED_)
#define AFX_MFCSDIWIZARD_H__94642331_1906_4CDB_BEC1_D98E02A52A6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCSdiWizardApp:
// See MFCSdiWizard.cpp for the implementation of this class
//

class CMFCSdiWizardApp : public CWinApp
{
public:
	CMFCSdiWizardApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCSdiWizardApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMFCSdiWizardApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCSDIWIZARD_H__94642331_1906_4CDB_BEC1_D98E02A52A6A__INCLUDED_)

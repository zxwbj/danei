// MFCCtrl2.h : main header file for the MFCCTRL2 application
//

#if !defined(AFX_MFCCTRL2_H__D529C14A_D114_4A6C_A5B5_99899F434218__INCLUDED_)
#define AFX_MFCCTRL2_H__D529C14A_D114_4A6C_A5B5_99899F434218__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCCtrl2App:
// See MFCCtrl2.cpp for the implementation of this class
//

class CMFCCtrl2App : public CWinApp
{
public:
	CMFCCtrl2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCCtrl2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFCCtrl2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCCTRL2_H__D529C14A_D114_4A6C_A5B5_99899F434218__INCLUDED_)

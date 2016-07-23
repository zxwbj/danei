// MFCThread.h : main header file for the MFCTHREAD application
//

#if !defined(AFX_MFCTHREAD_H__208978E2_8D8B_471C_B4A7_D3F31E8FC71C__INCLUDED_)
#define AFX_MFCTHREAD_H__208978E2_8D8B_471C_B4A7_D3F31E8FC71C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCThreadApp:
// See MFCThread.cpp for the implementation of this class
//

class CMFCThreadApp : public CWinApp
{
public:
	CMFCThreadApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCThreadApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFCThreadApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCTHREAD_H__208978E2_8D8B_471C_B4A7_D3F31E8FC71C__INCLUDED_)

// LabelSheet.cpp : implementation file
//

#include "stdafx.h"
#include "LabelProp.h"
#include "LabelSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLabelSheet

IMPLEMENT_DYNAMIC(CLabelSheet, CPropertySheet)

CLabelSheet::CLabelSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_page1);
	AddPage(&m_page2);

}

CLabelSheet::CLabelSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_page1);
	AddPage(&m_page2);
}

CLabelSheet::~CLabelSheet()
{
}


BEGIN_MESSAGE_MAP(CLabelSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CLabelSheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLabelSheet message handlers

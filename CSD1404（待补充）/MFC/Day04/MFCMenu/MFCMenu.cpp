#include "stdafx.h"
#include "resource.h"
class CMyFrameWnd : public CFrameWnd
{
	DECLARE_MESSAGE_MAP( )
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnNew( );
	afx_msg void OnInitMenuPopup( 
				CMenu *pPopup, UINT nPos, BOOL i );
	afx_msg void OnContextMenu( CWnd *pWnd, CPoint pt );
};
BEGIN_MESSAGE_MAP( CMyFrameWnd, CFrameWnd )
	ON_WM_CONTEXTMENU( )
	ON_WM_INITMENUPOPUP( )
//	ON_COMMAND( ID_NEW, OnNew )
	ON_WM_CREATE( )
END_MESSAGE_MAP( )
void CMyFrameWnd::OnContextMenu( CWnd *pWnd, CPoint pt )
{
	CMenu menu;
	menu.LoadMenu( IDR_MENU1 );
	CMenu *pPopup = menu.GetSubMenu( 1 );
//	::TrackPopupMenu( pPopup->m_hMenu,
//				TPM_CENTERALIGN|TPM_VCENTERALIGN,
//				pt.x, pt.y, 0, this->m_hWnd, NULL );
	pPopup->TrackPopupMenu( 
		TPM_CENTERALIGN|TPM_VCENTERALIGN, pt.x, pt.y,
		this );
}
void CMyFrameWnd::OnInitMenuPopup( 
					CMenu *pPopup, UINT nPos, BOOL i )
{
//	::CheckMenuItem( pPopup->m_hMenu, ID_NEW,
//					MF_BYCOMMAND|MF_CHECKED );
	pPopup->CheckMenuItem( ID_NEW, MF_CHECKED );
}
void CMyFrameWnd::OnNew( )
{
	AfxMessageBox( "框架类处理了新建被点击" );
}
int CMyFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	CMenu menu;
	menu.LoadMenu( IDR_MENU1 );
//	this->SetMenu( &menu );
	::SetMenu( this->m_hWnd, menu.m_hMenu );
	return CFrameWnd::OnCreate(lpCreateStruct);
}
class CMyWinApp : public CWinApp
{
	DECLARE_MESSAGE_MAP( )
public:
	virtual BOOL InitInstance( );
	afx_msg void OnNew( );
};
BEGIN_MESSAGE_MAP( CMyWinApp, CWinApp )
	ON_COMMAND( ID_NEW, OnNew )
END_MESSAGE_MAP( )
void CMyWinApp::OnNew( )
{
	AfxMessageBox( "应用程序类处理了新建被点击" );
}
CMyWinApp theApp;
BOOL CMyWinApp::InitInstance( )
{
	CMyFrameWnd *pFrame = new CMyFrameWnd;
	pFrame->Create( NULL, "MFCMenu" );
	m_pMainWnd = pFrame;
	pFrame->ShowWindow( SW_SHOW );
	pFrame->UpdateWindow( );
	return TRUE;
}

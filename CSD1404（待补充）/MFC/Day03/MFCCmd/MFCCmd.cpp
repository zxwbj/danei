#include "stdafx.h"
#define WM_MYMESSAGE WM_USER+1001
class CMyFrameWnd : public CFrameWnd
{
	DECLARE_MESSAGE_MAP( )
public:
	afx_msg int OnCreate( LPCREATESTRUCT pcs );
	afx_msg void OnPaint( );
	afx_msg LRESULT OnZjw(WPARAM wParam, LPARAM lParam );
};
BEGIN_MESSAGE_MAP( CMyFrameWnd, CFrameWnd )
	ON_MESSAGE( WM_MYMESSAGE, OnZjw )
	ON_WM_CREATE( )
	ON_WM_PAINT( )
END_MESSAGE_MAP( )
LRESULT CMyFrameWnd::OnZjw(WPARAM wParam, LPARAM lParam )
{
	AfxMessageBox( "自己定义的消息被处理" );
	return 0;
}
void CMyFrameWnd::OnPaint( )
{
	PAINTSTRUCT ps = { 0 };
	HDC hdc = ::BeginPaint( this->m_hWnd, &ps );
	::TextOut( hdc, 100, 100, "hello", 5 );
	::EndPaint( this->m_hWnd, &ps );
}
int CMyFrameWnd::OnCreate( LPCREATESTRUCT pcs )
{
	::CreateWindowEx( 0, "BUTTON", "OK", 
			WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
			100, 100, 100, 40, this->m_hWnd, (HMENU)1001,
			AfxGetInstanceHandle(), NULL );

	AfxMessageBox( "CMyFrameWnd::OnCreate" );
	::PostMessage( this->m_hWnd, WM_MYMESSAGE, 1, 2 );
	return CFrameWnd::OnCreate(pcs);
}
class CMyWinApp : public CWinApp
{
public:
	virtual BOOL InitInstance( );
};
CMyWinApp theApp;
BOOL CMyWinApp::InitInstance( )
{
	CMyFrameWnd *pFrame = new CMyFrameWnd;
	pFrame->Create( NULL, "MFCCmd" );
	m_pMainWnd = pFrame;
	pFrame->ShowWindow( SW_SHOW );
	pFrame->UpdateWindow( );
	return TRUE;
}
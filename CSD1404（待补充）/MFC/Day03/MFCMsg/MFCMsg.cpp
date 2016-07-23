#include "stdafx.h"
class CMyFrameWnd : public CFrameWnd
{
	DECLARE_MESSAGE_MAP( )
/*private:
	static const AFX_MSGMAP_ENTRY _messageEntries[]; 
protected: 
	static AFX_DATA const AFX_MSGMAP messageMap; 
	virtual const AFX_MSGMAP* GetMessageMap() const;*/ 

public:
	LRESULT OnCreate( WPARAM wParam, LPARAM lParam );//2
	LRESULT OnPaint( WPARAM wParam, LPARAM lParam );
	LRESULT OnMouseMove( WPARAM wParam, LPARAM lParam );
public:
	int m_x;
	int m_y;
	CMyFrameWnd( );
};
BEGIN_MESSAGE_MAP( CMyFrameWnd, CFrameWnd )
	ON_MESSAGE( WM_PAINT, OnPaint )
	ON_MESSAGE( WM_CREATE, OnCreate )//1
	ON_MESSAGE( WM_MOUSEMOVE, OnMouseMove )
END_MESSAGE_MAP( )
LRESULT CMyFrameWnd::OnMouseMove( WPARAM wParam, LPARAM lParam )
{
	m_x = LOWORD(lParam);
	m_y = HIWORD(lParam);
	::InvalidateRect( this->m_hWnd, NULL, TRUE );
	return 0;
}
CMyFrameWnd::CMyFrameWnd( )
{
	m_x = 100;
	m_y = 100;
}
LRESULT CMyFrameWnd::OnPaint( WPARAM wParam, LPARAM lParam )
{
	PAINTSTRUCT ps = { 0 };
	HDC hdc = ::BeginPaint( this->m_hWnd, &ps );
	::TextOut( hdc, this->m_x, this->m_y, "hello", 5 );
	::EndPaint( m_hWnd, &ps );
	return 0;
}
/*
const AFX_MSGMAP* CMyFrameWnd::GetMessageMap() const 
{
	return &CMyFrameWnd::messageMap; 
} 
AFX_COMDAT AFX_DATADEF const AFX_MSGMAP 
CMyFrameWnd::messageMap = 
{ 
	&CFrameWnd::messageMap, 
	&CMyFrameWnd::_messageEntries[0] 
}; 
AFX_COMDAT const AFX_MSGMAP_ENTRY 
CMyFrameWnd::_messageEntries[] = 
{ 
	{ WM_CREATE, 0, 0, 0, AfxSig_lwl, 
		(AFX_PMSG)(AFX_PMSGW)
		(LRESULT (AFX_MSG_CALL CWnd::*)
		(WPARAM, LPARAM))&OnCreate },
	{0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 } 
}; */




//3
LRESULT CMyFrameWnd::OnCreate( WPARAM wParam, LPARAM lParam )
{//此函数的this为pFrame
	AfxMessageBox( "CMyFrameWnd::OnCreate" );
	return 0;
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
	pFrame->Create( NULL, "MFCMsg" );
	m_pMainWnd = pFrame;
	pFrame->ShowWindow( SW_SHOW );
	pFrame->UpdateWindow( );
	return TRUE;
}


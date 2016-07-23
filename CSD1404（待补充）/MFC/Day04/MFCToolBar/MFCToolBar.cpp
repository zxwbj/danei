#include "stdafx.h"
#include "resource.h"
UINT g_hIndicator[] = {
			0,
			IDS_TIME,
			IDS_POS
};
class CMyFrameWnd : public CFrameWnd
{
	DECLARE_MESSAGE_MAP( )
public:
	CToolBar toolbar;
	CStatusBar statusbar;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnNew( );
	afx_msg void OnSet( );
	afx_msg void OnInitMenuPopup( 
				CMenu *pPopup, UINT nPos, BOOL i );
	afx_msg void OnTool( );
};
BEGIN_MESSAGE_MAP( CMyFrameWnd, CFrameWnd )
	ON_COMMAND( ID_TOOL, OnTool )
	ON_WM_INITMENUPOPUP( )
	ON_COMMAND( ID_SET, OnSet )
	ON_COMMAND( ID_NEW, OnNew )
	ON_WM_CREATE( )
END_MESSAGE_MAP( )
void CMyFrameWnd::OnTool( )
{
	if( toolbar.IsWindowVisible() )
	{
		this->ShowControlBar( &toolbar, FALSE, FALSE );
	}else{
		this->ShowControlBar( &toolbar, TRUE, FALSE );
	}
}
void CMyFrameWnd::OnInitMenuPopup( 
					CMenu *pPopup, UINT nPos, BOOL i )
{
	if( toolbar.IsWindowVisible() )
	{
		pPopup->CheckMenuItem( ID_TOOL, MF_CHECKED );
	}else{
		pPopup->CheckMenuItem( ID_TOOL, MF_UNCHECKED );
	}
}
void CMyFrameWnd::OnSet( )
{
	AfxMessageBox( "绿色按钮被点击" );
}
void CMyFrameWnd::OnNew( )
{
	AfxMessageBox( "新建被点击" );
}
int CMyFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	toolbar.CreateEx( this, TBSTYLE_TRANSPARENT, 
				WS_CHILD|WS_VISIBLE|CBRS_ALIGN_TOP|
				CBRS_GRIPPER|CBRS_SIZE_DYNAMIC|
				CBRS_TOOLTIPS|CBRS_FLYBY );
	toolbar.LoadToolBar( IDR_TOOLBAR1 );
	toolbar.EnableDocking( CBRS_ALIGN_ANY );
	this->EnableDocking( CBRS_ALIGN_ANY );
	this->DockControlBar( &toolbar,
						AFX_IDW_DOCKBAR_TOP );
	toolbar.SetWindowText( "工具栏" );

	statusbar.CreateEx( this );
	statusbar.SetIndicators( g_hIndicator, 3 );
	return CFrameWnd::OnCreate(lpCreateStruct);
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
	pFrame->Create( NULL, "MFCToolBar", 
		WS_OVERLAPPEDWINDOW, CFrameWnd::rectDefault,
		NULL, MAKEINTRESOURCE(IDR_MENU1) );
	m_pMainWnd = pFrame;
	pFrame->ShowWindow( SW_SHOW );
	pFrame->UpdateWindow( );
	return TRUE;
}



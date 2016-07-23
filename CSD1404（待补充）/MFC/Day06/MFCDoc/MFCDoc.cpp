#include "stdafx.h"
#include "resource.h"
class CZjw : public CCmdTarget
{
	DECLARE_MESSAGE_MAP( )
public:
	afx_msg void OnNew( );
};
BEGIN_MESSAGE_MAP( CZjw, CCmdTarget )
	ON_COMMAND( ID_NEW, OnNew )
END_MESSAGE_MAP( )
void CZjw::OnNew( )
{
	AfxMessageBox( "zjw�ദ�����½������" );
}
class CMyDoc : public CDocument
{
	DECLARE_MESSAGE_MAP( )
public:
	CString strDoc;
	afx_msg void OnNew( );
};
BEGIN_MESSAGE_MAP( CMyDoc, CDocument )
//	ON_COMMAND( ID_NEW, OnNew )
END_MESSAGE_MAP( )
void CMyDoc::OnNew( )
{
	strDoc = "hello dataferstgregre";
	this->UpdateAllViews(NULL);
}
class CMyView : public CEditView
{
	DECLARE_MESSAGE_MAP( )
	DECLARE_DYNCREATE( CMyView )
public:
	afx_msg int OnCreate( LPCREATESTRUCT pcs );
	virtual void OnUpdate(
		CView* pSender, LPARAM lHint, CObject* pHint);
};
BEGIN_MESSAGE_MAP( CMyView, CEditView )
	ON_WM_CREATE( )
END_MESSAGE_MAP( )
IMPLEMENT_DYNCREATE( CMyView, CEditView )
void CMyView::OnUpdate(
		CView* pSender, LPARAM lHint, CObject* pHint)
{
	CMyDoc *pDoc = (CMyDoc*)this->m_pDocument;
	this->SetWindowText( pDoc->strDoc );
}
int CMyView::OnCreate( LPCREATESTRUCT pcs )
{
	return CEditView::OnCreate(pcs);
	//����ͼ�������ĵ��������󶨹�ϵ
}
class CMyFrameWnd : public CFrameWnd
{
	DECLARE_MESSAGE_MAP( )
public:
	afx_msg int OnCreate( LPCREATESTRUCT pcs );
	virtual BOOL OnCreateClient(
		LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual BOOL OnCmdMsg(
		UINT nID, int nCode, 
		void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
public:
	CSplitterWnd split;
};
BEGIN_MESSAGE_MAP( CMyFrameWnd, CFrameWnd )
	ON_WM_CREATE( )
END_MESSAGE_MAP( )
BOOL CMyFrameWnd::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	CZjw zjw;
	if( zjw.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo) )
		return TRUE;
	return CFrameWnd::OnCmdMsg(nID, nCode, 
					pExtra, pHandlerInfo);
}
BOOL CMyFrameWnd::OnCreateClient(
		LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	split.CreateStatic( this, 1, 2 );
	split.CreateView( 0, 0, pContext->m_pNewViewClass,
						CSize(100,100), pContext );
	split.CreateView( 0, 1, RUNTIME_CLASS(CMyView),
						CSize(100,100), pContext );
	return TRUE;
}
int CMyFrameWnd::OnCreate( LPCREATESTRUCT pcs )
{
	return CFrameWnd::OnCreate(pcs);//��������ͼ����
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
	AfxMessageBox( "Ӧ�ó����ദ���½������" );
}
CMyWinApp theApp;
BOOL CMyWinApp::InitInstance( )
{
	CMyFrameWnd *pFrame = new CMyFrameWnd;
	CCreateContext cct;
	cct.m_pCurrentDoc = new CMyDoc;
	cct.m_pNewViewClass = RUNTIME_CLASS(CMyView);
	pFrame->LoadFrame( IDR_MENU1, WS_OVERLAPPEDWINDOW,
					NULL, &cct );
	m_pMainWnd = pFrame;
	pFrame->ShowWindow( SW_SHOW );
	pFrame->UpdateWindow( );
	return TRUE;
}


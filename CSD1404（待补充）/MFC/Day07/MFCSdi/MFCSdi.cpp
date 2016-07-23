#include "stdafx.h"
#include "resource.h"
class CMyDoc : public CDocument
{
	DECLARE_DYNCREATE( CMyDoc )
public:
	CString strDoc;
};
IMPLEMENT_DYNCREATE( CMyDoc, CDocument )
class CMyView : public CEditView
{
	DECLARE_MESSAGE_MAP( )
	DECLARE_DYNCREATE( CMyView )
public:
	afx_msg BOOL OnSetCursor( 
			CWnd*pWnd, UINT nHit, UINT message );
	virtual void OnUpdate(
		CView* pSender, LPARAM lHint, CObject* pHint);
};
BEGIN_MESSAGE_MAP( CMyView, CEditView )
	ON_WM_SETCURSOR( )
END_MESSAGE_MAP( )
IMPLEMENT_DYNCREATE( CMyView, CEditView )
void CMyView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	CMyDoc *pDoc = (CMyDoc*)this->m_pDocument;
	this->SetWindowText( pDoc->strDoc );
}
BOOL CMyView::OnSetCursor( CWnd*pWnd, UINT nHit, UINT message )
{
	HCURSOR hBall = ::LoadCursor( AfxGetInstanceHandle(),
						MAKEINTRESOURCE(IDR_MENU1) );
	::SetCursor( hBall );
	return 0;//CEditView::OnSetCursor( pWnd, nHit, message );
}
class CMyFrameWnd : public CFrameWnd
{
	DECLARE_DYNCREATE( CMyFrameWnd )
};
IMPLEMENT_DYNCREATE( CMyFrameWnd, CFrameWnd )
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
	//�ĵ����ԱstrDoc��ֵ
	CMyFrameWnd *pFrame = (CMyFrameWnd*)this->m_pMainWnd;
	CMyView *pView = (CMyView*)pFrame->GetActiveView();
	CMyDoc *pDoc = (CMyDoc*)pView->GetDocument();
	pDoc->strDoc = "fesgfregregre";
	//ˢ�º�����ĵ�������������ͼ����
	pDoc->UpdateAllViews( NULL );
}
CMyWinApp theApp;
BOOL CMyWinApp::InitInstance( )
{
	CSingleDocTemplate *pTemplate=new CSingleDocTemplate(
							IDR_MENU1,
							RUNTIME_CLASS(CMyDoc),
							RUNTIME_CLASS(CMyFrameWnd),
							RUNTIME_CLASS(CMyView) );
	AddDocTemplate(pTemplate);
	OnFileNew( );
	m_pMainWnd->ShowWindow( SW_SHOW );
	m_pMainWnd->UpdateWindow( );
	return TRUE;
}



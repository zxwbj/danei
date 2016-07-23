#include "stdafx.h"
class CMyView : public CView
{
	DECLARE_DYNCREATE( CMyView )
public:
	virtual void OnDraw( CDC *pDC );
};
IMPLEMENT_DYNCREATE( CMyView, CView )
void CMyView::OnDraw( CDC *pDC )
{
	pDC->TextOut( 100, 100, "�Լ�����ͼ" );
}
class CMyFrameWnd : public CFrameWnd
{
public:
	CSplitterWnd split1;//�����ο��
	CSplitterWnd split2;//�����ο��
	virtual BOOL OnCreateClient(
		LPCREATESTRUCT lpcs, CCreateContext* pContext);
};
BOOL CMyFrameWnd::OnCreateClient(
		LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	CCreateContext cct;
	cct.m_pNewViewClass = RUNTIME_CLASS(CMyView);
	split1.Create( this, 2, 2, CSize(100,100), &cct );
	return TRUE;
/*	
	//��̬�з�
	split1.CreateStatic( this, 1, 2 );
	split2.CreateStatic( &split1, 2, 1, 
		WS_CHILD|WS_VISIBLE, split1.IdFromRowCol(0,0) );
	split2.CreateView( 1, 0, RUNTIME_CLASS(CMyView),
					CSize(100,100), pContext );
	split2.CreateView( 0, 0, RUNTIME_CLASS(CEditView),
					CSize(100,100), pContext );
	split1.CreateView( 0, 1, RUNTIME_CLASS(CHtmlView),
					CSize(100,100), pContext );

	CHtmlView *pView = (CHtmlView*)split1.GetPane( 0, 1 );
	pView->Navigate( "c:/" );
	split1.SetRowInfo( 0, 200, 100 );
	split1.SetColumnInfo( 0, 200, 100 );
	return TRUE;//Ϊ�β��������麯��*/
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
	pFrame->Create( NULL, "MFCSplit" );
	m_pMainWnd = pFrame;
	pFrame->ShowWindow( SW_SHOW );
	pFrame->UpdateWindow( );
	return TRUE;
}



#include "stdafx.h"
class CMyFrameWnd : public CFrameWnd
{
};
class CMyWinApp : public CWinApp
{
public:
	CMyWinApp( );
	virtual BOOL InitInstance( );
};
CMyWinApp::CMyWinApp( )
{
}

CMyWinApp theApp;//���Ƶ�
BOOL CMyWinApp::InitInstance( )
{//�˺�����thisΪ&theApp
	CMyFrameWnd *pFrame = new CMyFrameWnd;
	pFrame->Create( NULL, "MFCBase" );
	this->m_pMainWnd = pFrame;
	pFrame->ShowWindow( SW_SHOW );
	pFrame->UpdateWindow( );
	return TRUE;
}


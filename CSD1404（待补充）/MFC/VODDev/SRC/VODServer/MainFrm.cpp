// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "VODServer.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_TOOLBAR_NAVIGATE, OnToolbarNavigate)
	ON_UPDATE_COMMAND_UI(ID_TOOLBAR_NAVIGATE, OnUpdateToolbarNavigate)
	ON_COMMAND(ID_TOOLBAR_EDIT, OnToolbarEdit)
	ON_UPDATE_COMMAND_UI(ID_TOOLBAR_EDIT, OnUpdateToolbarEdit)
	ON_COMMAND(ID_SVR_START, OnSvrStart)
	ON_COMMAND(ID_SVR_STOP, OnSvrStop)
	ON_UPDATE_COMMAND_UI(ID_SVR_START, OnUpdateSvrStart)
	ON_UPDATE_COMMAND_UI(ID_SVR_STOP, OnUpdateSvrStop)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	//�������ݿ�
	m_adoConnection.ConnectAccess("../../DB/VODDB.mdb");
	m_bSvrStart=TRUE;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	//������������
	m_wndToolBar.SetButtonText(0," ���͵��� ");
	m_wndToolBar.SetButtonText(1," ��Ƶ�༭ ");
	m_wndToolBar.SetButtonText(2," �������� ");
	m_wndToolBar.SetButtonText(3," ����ֹͣ ");
	/////////////����������/////////////////
	CRect rc(0, 0, 0, 0);
	CSize sizeMax(0, 0);
	CToolBarCtrl& bar = m_wndToolBar.GetToolBarCtrl();
	for (int nIndex = bar.GetButtonCount() - 1; nIndex >= 0; nIndex--)
	{
		bar.GetItemRect(nIndex, rc);
		
		rc.NormalizeRect();
		sizeMax.cx = __max(rc.Size().cx, sizeMax.cx);
		sizeMax.cy = __max(rc.Size().cy, sizeMax.cy);
	}
	//sizeMax.cx += 10;
	m_wndToolBar.SetSizes(sizeMax, CSize(20,18));
	
	//�������Ĵ�����ͣ��
	if (!m_LeftCtrBar.Create(_T("����������"), this, CSize(230,260),TRUE,123))
	{
		TRACE0("Failed to create mybar\n");
		return -1;
	}
	if (!m_BottomCtrBar.Create(_T("�༭������"), this,CSize(200,170),TRUE,124))
	{
		TRACE0("Failed to create mybar\n");
		return -1;
	}
	m_LeftCtrBar.SetBarStyle(m_LeftCtrBar.GetBarStyle() | CBRS_TOOLTIPS
		| CBRS_FLYBY | CBRS_SIZE_DYNAMIC);
	m_BottomCtrBar.SetBarStyle(m_BottomCtrBar.GetBarStyle() | CBRS_TOOLTIPS
		| CBRS_FLYBY | CBRS_SIZE_DYNAMIC);
	m_LeftCtrBar.EnableDocking(CBRS_ALIGN_ANY);
	m_BottomCtrBar.EnableDocking(CBRS_ALIGN_ANY);
 
	DockControlBar(&m_BottomCtrBar, AFX_IDW_DOCKBAR_BOTTOM);  //ͣ���ڵײ� 
    DockControlBar(&m_LeftCtrBar, AFX_IDW_DOCKBAR_LEFT);      //ͣ�������
   	/////////ʹ������ͣ����ʾ��ͬ��ͷ��////
#ifdef _SCB_REPLACE_MINIFRAME
    m_pFloatingFrameClass = RUNTIME_CLASS(CSCBMiniDockFrameWnd);
#endif //_SCB_REPLACE_MINIFRAME
	//�ײ��Ĺ���������ӶԻ���

	if(!m_dlgVideo.Create(IDD_DLG_VIDEO,&m_BottomCtrBar))
		return -1;
	m_dlgVideo.ShowWindow(SW_SHOW);
    m_dlgVideo.InitVideoTypeCtrl();
	//���ؼ�
	if (!m_wndTree.Create(WS_CHILD|WS_VISIBLE|
		TVS_HASLINES|TVS_HASBUTTONS|TVS_LINESATROOT,
		CRect(0, 0, 0, 0), &m_LeftCtrBar, 100))
	{
		TRACE0("Failed to create instant bar child\n");
		return -1;
	}
	m_wndTree.ModifyStyleEx(0, WS_EX_CLIENTEDGE);
	//mazhiguo
	InitTypeTreeCtrl();

	//����������
	m_NetServer.InitServer();
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	//ȥ���������е��ĵ���
     cs.style&=~FWS_ADDTOTITLE;
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnToolbarNavigate() 
{
	// TODO: Add your command handler code here
	ShowControlBar(&m_LeftCtrBar, !m_LeftCtrBar.IsVisible(), FALSE);

}

void CMainFrame::OnUpdateToolbarNavigate(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_LeftCtrBar.IsVisible());	

}

void CMainFrame::OnToolbarEdit() 
{
	// TODO: Add your command handler code here
	ShowControlBar(&m_BottomCtrBar, !m_BottomCtrBar.IsVisible(), FALSE);

}

void CMainFrame::OnUpdateToolbarEdit(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_BottomCtrBar.IsVisible());	

}

void CMainFrame::InitTypeTreeCtrl()
{
	CMainFrame *pWnd=(CMainFrame*)AfxGetMainWnd();
    CTypeManager typeMgr(&pWnd->m_adoConnection);
	CList<CType,CType> lstTypes;
	typeMgr.GetAllType(&lstTypes);
	CType type;
	HTREEITEM hRoot = m_wndTree.InsertItem(_T("��������"));
	for (int i=0;i<lstTypes.GetCount();i++)
	{
		type=lstTypes.GetAt(lstTypes.FindIndex(i));
		HTREEITEM hItem= m_wndTree.InsertItem(type.strTypeName,hRoot);
		m_wndTree.SetItemData(hItem,type.nTypeID);
	}
	m_wndTree.SetItemHeight(20);
	m_wndTree.Expand(hRoot,TVE_EXPAND);
}

void CMainFrame::OnSvrStart() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnSvrStop() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnUpdateSvrStart(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CMainFrame::OnUpdateSvrStop(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

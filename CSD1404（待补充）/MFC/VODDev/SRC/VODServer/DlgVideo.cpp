// DlgVideo.cpp : implementation file
//

#include "stdafx.h"
#include "VODServer.h"
#include "DlgVideo.h"


#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgVideo dialog


CDlgVideo::CDlgVideo(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgVideo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgVideo)
	m_strVideoDesp = _T("");
	m_strVideoName = _T("");
	m_strVideoPath = _T("");
	m_strVideoType = _T("");
	m_strVideoID = _T("");
	//}}AFX_DATA_INIT
}


void CDlgVideo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgVideo)
	DDX_Control(pDX, IDC_OK, m_wndOK);
	DDX_Control(pDX, IDC_VIDEO_TYPE, m_cboType);
	DDX_Text(pDX, IDC_VIDEO_DESP, m_strVideoDesp);
	DDX_Text(pDX, IDC_VIDEO_NAME, m_strVideoName);
	DDX_Text(pDX, IDC_VIDEO_PATH, m_strVideoPath);
	DDX_CBString(pDX, IDC_VIDEO_TYPE, m_strVideoType);
	DDX_Text(pDX, IDC_VIDEO_ID, m_strVideoID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgVideo, CDialog)
	//{{AFX_MSG_MAP(CDlgVideo)
	ON_BN_CLICKED(IDC_OPENFILE, OnOpenfile)
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_BN_CLICKED(IDC_NEW, OnNew)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgVideo message handlers

void CDlgVideo::OnOpenfile() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CFileDialog dlg(TRUE);
	if (IDOK!=dlg.DoModal())return;
	m_strVideoPath=dlg.GetPathName();
	UpdateData(FALSE);

}

BOOL CDlgVideo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//mazhiguo
//	InitVideoTypeCtrl();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgVideo::InitVideoTypeCtrl()
{
  
   CMainFrame *pWnd=(CMainFrame*)AfxGetMainWnd();
   CTypeManager typeMgr(&pWnd->m_adoConnection);
   CList<CType,CType> lstTypes;
   typeMgr.GetAllType(&lstTypes);
   CType type;
   for (int i=0;i<lstTypes.GetCount();i++)
   {
	   type=lstTypes.GetAt(lstTypes.FindIndex(i));
	   m_cboType.AddString(type.strTypeName);
	   m_cboType.SetItemData(i,type.nTypeID);
   }
}


void CDlgVideo::OnOk() 
{
	// TODO: Add your control notification handler code here
	CMainFrame *pWnd=(CMainFrame*)AfxGetMainWnd();
	CVideoManager videoMgr(&pWnd->m_adoConnection);
	UpdateData(TRUE);
	if (m_strVideoType=="")
	{
		MessageBox("��ѡ����Ƶ���ͣ�");
		return;
	}
	CVideo v;
	v.strVideoName=m_strVideoName;
	v.strVideoDesp=m_strVideoDesp;
	v.strVideoPath=m_strVideoPath;
	int nCurSel=m_cboType.GetCurSel();
	v.nTypeid=m_cboType.GetItemData(nCurSel);
	//��ȡ��ǰ���ı�

	
	if (m_strVideoID=="")
	{
		//ִ�в������
        videoMgr.InsertVideo(v);
		//���ԭ������
        ClearCtrlData();
	}
	else
	{
		v.nVideoID=atoi(m_strVideoID);
		//ִ�и������ݲ���
        videoMgr.UpdateVideo(v,v.nVideoID); 

	}
   	BindDataGrid();
	//test
	UpdateData(FALSE);
}

void CDlgVideo::OnNew()
{
    ClearCtrlData();
	//��ť�����ɸ��±�Ϊ����
	m_wndOK.SetWindowText("����");

}

void CDlgVideo::ClearCtrlData()
{
	m_strVideoID="";
	m_strVideoName="";
	m_strVideoDesp="";
	m_strVideoType="";
	m_strVideoPath="";
   UpdateData(FALSE);
}

void CDlgVideo::OnDel() 
{
	// TODO: Add your control notification handler code here
	CMainFrame *pWnd=(CMainFrame*)AfxGetMainWnd();
   	CVideoManager videoMgr(&pWnd->m_adoConnection);
    int nVideoID=atoi(m_strVideoID);
	videoMgr.DeleteVideo(nVideoID);
	//���ԭ������
    ClearCtrlData();
	//���°���ʾ
    BindDataGrid();
	m_wndOK.SetWindowText("����");

}

void CDlgVideo::BindDataGrid()
{
	CMainFrame *pWnd=(CMainFrame*)AfxGetMainWnd();
	m_Recordset.SetAdoConnection(&pWnd->m_adoConnection);
	m_Recordset.SetCursorLocation();
	CString strSql=
		"select videoInfo.id as ���,videoName as ��Ƶ����,videoDesp as ��Ƶ����,videoPath as ��Ƶ·��,typeName as �������� from videoInfo,TypeInfo where videoInfo.typeid=TypeInfo.id";
	m_Recordset.Open(strSql, adCmdText);
	CVODServerView *pView=(CVODServerView *)((CFrameWnd*)AfxGetMainWnd())->GetActiveView();
	pView->m_wndGrid.SetRefDataSource((LPUNKNOWN)m_Recordset.GetRecordset());
	pView->m_wndGrid.Refresh();
}

BOOL CDlgVideo::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class

	if (pMsg->message==WM_KEYDOWN)
	{
		if (pMsg->wParam==VK_ESCAPE)
		{
			return TRUE;
		}
		if (pMsg->wParam==VK_RETURN)
		{
			return TRUE;
		}
	}
	
	return CDialog::PreTranslateMessage(pMsg);
}

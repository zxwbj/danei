// MFCListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCList.h"
#include "MFCListDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCListDlg dialog

CMFCListDlg::CMFCListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFCListDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFCListDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFCListDlg)
	DDX_Control(pDX, IDC_LIST, m_wndList);
	DDX_Control(pDX, IDC_STYLE, m_wndStyle);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFCListDlg, CDialog)
	//{{AFX_MSG_MAP(CMFCListDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_STYLE, OnSelchangeStyle)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, OnDblclkList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCListDlg message handlers

BOOL CMFCListDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_wndStyle.SetCurSel(3);
	InitListCtrl();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCListDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCListDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCListDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFCListDlg::InitListCtrl()
{
    // 1 ����ͼ���б��Сͼ���б�
	m_ilNormal.Create(IDB_NORMAL,32,1,RGB(0,0,0));
	m_ilSmall.Create(IDB_SMALL,18,1,RGB(0,0,0));
	// 2 ��ͼ���б����õ��ؼ���
	m_wndList.SetImageList(&m_ilNormal,LVSIL_NORMAL);
	m_wndList.SetImageList(&m_ilSmall,LVSIL_SMALL);
	// 3 ����ؼ�����
	m_wndList.InsertColumn(0,"����",LVCFMT_LEFT,100);
	m_wndList.InsertColumn(1,"��С",LVCFMT_LEFT,100);
	m_wndList.InsertColumn(2,"����",LVCFMT_LEFT,100);
	m_wndList.InsertColumn(3,"�޸�����",LVCFMT_LEFT,150);
    // 4 ����������
	m_wndList.InsertItem(0,"�ļ�",1);
	m_wndList.InsertItem(1,"�ļ���",0);
	// 5 �����������е��ı�
	m_wndList.SetItemText(0,1,"125k");
	m_wndList.SetItemText(0,3,"2010-10-10");
	m_wndList.SetItemText(1,2,"�ļ���");
	m_wndList.SetItemText(1,3,"2014-09-01");
	//��ʾc����Ŀ¼�µ��ļ���Ŀ¼
    ShowData("c:");
	// 6 ���ÿؼ��ı���ͼƬ
	//��ʼ��OLE��
	AfxOleInit();
	m_wndList.SetBkImage("f:\\bg.bmp");
	//��������ı���ɫΪ͸��
	m_wndList.SetTextBkColor(CLR_NONE);
}

void CMFCListDlg::ShowData(CString sPath)
{
   // 1 ������µ�����ǰ��������տؼ�
   m_wndList.DeleteAllItems();
   m_lstPath.RemoveAll();
   // 2 ���CFileFind���ȡ������ӵ��ؼ�
   CFileFind find;
   BOOL bRet=find.FindFile(sPath+"\\*.*");
   int nItem=0;//�ؼ������������
   while(bRet)
   {
	   bRet=find.FindNextFile();
	   CString sName=find.GetFileName();
	   if (find.IsDirectory())
	   {
		   m_wndList.InsertItem(nItem,sName,0);
		   m_wndList.SetItemText(nItem,2,"�ļ���");
		  
	   }
	   else
	   {
		   m_wndList.InsertItem(nItem,sName,1);
		   int nLen=find.GetLength();
		   CString strLen;
		   strLen.Format("%d Byte",nLen);
		   m_wndList.SetItemText(nItem,1,strLen);
	   }
	   //����������
	   CTime t;
	   find.GetLastWriteTime(t);
       CString sTime=t.Format("%Y-%m-%d %H:%M");
	   m_wndList.SetItemText(nItem,3,sTime);
      /*
	   //ͨ��������ĸ������ݱ���·��
	   CString *pPath=new CString;
	   *pPath=find.GetFilePath();
	   m_wndList.SetItemData(nItem,(DWORD)pPath);
      */
	   //������������ļ�·��
	   m_lstPath.AddTail(find.GetFilePath());
	   nItem++;
   }
   find.Close();
}

void CMFCListDlg::OnSelchangeStyle() 
{
	// ������Ͽ�ؼ���ѡ�������б�ؼ���ʾ���
	int nSel=m_wndStyle.GetCurSel();
	switch(nSel)
	{
	case 0://ͼ��
		m_wndList.ModifyStyle(
			LVS_SMALLICON|LVS_LIST|LVS_REPORT,LVS_ICON);
		break;
	case 1://Сͼ��
		m_wndList.ModifyStyle(
			LVS_ICON|LVS_LIST|LVS_REPORT,LVS_SMALLICON);
		break;
	case 2://�б�
		m_wndList.ModifyStyle(
			LVS_SMALLICON|LVS_ICON|LVS_REPORT,LVS_LIST );
		break;
	case 3://����
		m_wndList.ModifyStyle(
			LVS_SMALLICON|LVS_ICON|LVS_LIST,LVS_REPORT  );
		break;

	}
}

void CMFCListDlg::OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// 1 ��ȡ˫��ʱ��ѡ��
    LPNMITEMACTIVATE pItem=(LPNMITEMACTIVATE)pNMHDR;
    int nItem=pItem->iItem;
	if (nItem==-1)return;
	/*
	// 2 ����������ȡ��������(·����ָ��)
	CString *pPath=(CString*)m_wndList.GetItemData(nItem);
	ShowData(*pPath);
	*/
	//�������л�ȡ�ļ�·��
	CString sPath=
		m_lstPath.GetAt(m_lstPath.FindIndex(nItem));
	ShowData(sPath);
	*pResult = 0;
}

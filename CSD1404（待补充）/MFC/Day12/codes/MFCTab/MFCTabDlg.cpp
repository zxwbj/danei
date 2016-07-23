// MFCTabDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTab.h"
#include "MFCTabDlg.h"

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
// CMFCTabDlg dialog

CMFCTabDlg::CMFCTabDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFCTabDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFCTabDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCTabDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFCTabDlg)
	DDX_Control(pDX, IDC_TAB, m_wndTab);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFCTabDlg, CDialog)
	//{{AFX_MSG_MAP(CMFCTabDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, OnSelchangeTab)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCTabDlg message handlers

BOOL CMFCTabDlg::OnInitDialog()
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
	
	//1 �����ǩ
	m_wndTab.InsertItem(0,"��ǩ1");
	m_wndTab.InsertItem(1,"��ǩ2");
	//2 ��Tab�ؼ�Ϊ�����ڣ������Ի���
    m_dlg1.Create(IDD_DIALOG1,&m_wndTab);
	m_dlg2.Create(IDD_DIALOG2,&m_wndTab);
    //3 ����Tab�ؼ���λ�óߴ����öԻ����λ�úͳߴ�
	CRect rt;
	m_wndTab.GetClientRect(&rt);
    rt.top+=20;
	rt.left+=1;
	rt.right-=1;
	rt.bottom-=1;
	m_dlg1.MoveWindow(&rt,TRUE);
	m_dlg2.MoveWindow(&rt,TRUE);
	//4 ���öԻ������ʾ״̬
	m_dlg1.ShowWindow(SW_SHOW);
	m_dlg2.ShowWindow(SW_HIDE);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCTabDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCTabDlg::OnPaint() 
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
HCURSOR CMFCTabDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFCTabDlg::OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// ����Tab�ؼ��ĵ�ǰѡ�����öԻ������ʾ״̬
	int nSel=m_wndTab.GetCurSel();
	switch(nSel)
	{
	case 0://��ǩ1
        m_dlg1.ShowWindow(SW_SHOW);
		m_dlg2.ShowWindow(SW_HIDE);
		break;
	case 1://��ǩ2
        m_dlg2.ShowWindow(SW_SHOW);
		m_dlg1.ShowWindow(SW_HIDE);
		break;
	}
	
	*pResult = 0;
}

// MFCCtrlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCCtrl.h"
#include "MFCCtrlDlg.h"

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
// CMFCCtrlDlg dialog

CMFCCtrlDlg::CMFCCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFCCtrlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFCCtrlDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFCCtrlDlg)
	DDX_Control(pDX, IDC_LIST2, m_wndList2);
	DDX_Control(pDX, IDC_LIST1, m_wndList1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFCCtrlDlg, CDialog)
	//{{AFX_MSG_MAP(CMFCCtrlDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCCtrlDlg message handlers

BOOL CMFCCtrlDlg::OnInitDialog()
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
	//Ϊ��һ���б��ؼ����������
	m_wndList1.AddString("����");
	m_wndList1.AddString("�Ϻ�");
	m_wndList1.AddString("���");
	m_wndList1.AddString("����");
   
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCCtrlDlg::OnPaint() 
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
HCURSOR CMFCCtrlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFCCtrlDlg::OnButton1() 
{
	// 1 ��ȡListBox1�ĵ�ǰѡ��
	int nSel=m_wndList1.GetCurSel();
	if (nSel==-1)return;
	// 2 ��ȡ��ǰѡ����ı�
	CString sCity;
	m_wndList1.GetText(nSel,sCity);
	// 3 ���ı���ӵ�ListBox2��
	m_wndList2.AddString(sCity);
	// 4 ɾ��ListBox1��ѡ��
	m_wndList1.DeleteString(nSel);
}

void CMFCCtrlDlg::OnButton2() 
{
	// 1 ����ListBox1��ѡ���ӵ�ListBox2
    int nCount=m_wndList1.GetCount();
	CString sCity;
	for (int i=0;i<nCount;i++)
	{
       m_wndList1.GetText(i,sCity);
	   m_wndList2.AddString(sCity);
	   
	}
	// 2 ɾ��ListBox1������ѡ��
	m_wndList1.ResetContent();
}

void CMFCCtrlDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	
}

void CMFCCtrlDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	
}

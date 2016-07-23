// MFCODBCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCODBC.h"
#include "MFCODBCDlg.h"

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
// CMFCODBCDlg dialog

CMFCODBCDlg::CMFCODBCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFCODBCDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFCODBCDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCODBCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFCODBCDlg)
	DDX_Control(pDX, IDC_LIST, m_wndList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFCODBCDlg, CDialog)
	//{{AFX_MSG_MAP(CMFCODBCDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SHOW, OnShow)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCODBCDlg message handlers

BOOL CMFCODBCDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCODBCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCODBCDlg::OnPaint() 
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
HCURSOR CMFCODBCDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFCODBCDlg::OnShow() 
{
	// 1 ������Դ(�������ݿ�)
    if (!m_db.Open("TestDB"))
    {
		MessageBox("������ԴTestDBʧ�ܣ�");
		return;
    }
    // ִ��Sql����������ɾ���ĵĲ���
	CString strSql=
		//"insert into TBL_MSG(msg_id,msg_sender) values('5','55')";
        //"update TBL_MSG set msg_sender='456' where msg_id='5'";
	    "delete from TBL_MSG where msg_id='5'";   
	m_db.ExecuteSQL(strSql);

    // 2 �����ݱ��е�������ʾ���ؼ���
    CRecordset set(&m_db);
	//2.1 �򿪱�
	set.Open(CRecordset::forwardOnly,//����ľ�̬�α�
		"select * from TBL_MSG");
    //2.2 ��ȡ���ݱ��ֶε�����
	int nCount=set.GetODBCFieldCount();
    //2.3 ��ӿؼ���֮ǰ��ɾ���ؼ�ԭ������
    while(m_wndList.DeleteColumn(0));
	//2.4 ��ѭ���У���ȡ�ֶεı�������Ϊ�ؼ����б���
	for (int i=0;i<nCount;i++)
	{
		CODBCFieldInfo info;
		set.GetODBCFieldInfo(i,info);
		m_wndList.InsertColumn(i,info.m_strName,
			LVCFMT_LEFT,100);

	}
    //2.5 ��ӿؼ���������ǰ��ɾ��ԭ��������
	m_wndList.DeleteAllItems();
	//2.6 ��ȡ���ݱ��������ӵ��ؼ���
	int nItem=0;//�б�ؼ��������������
    while(!set.IsEOF())
	{
		for (int i=0;i<nCount;i++)
		{
			CString strValue;
			set.GetFieldValue(i,strValue);
			if (i==0)
			{
				m_wndList.InsertItem(nItem,strValue);
			}
			else
			{
               m_wndList.SetItemText(nItem,i,strValue);
			}
		}
		nItem++;
		set.MoveNext();//�ƶ�����һ����¼
	}
 
    //�رռ�¼��
	set.Close();

	//�ر����ݿ�
	m_db.Close();

	
}

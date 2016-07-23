// MyFormView.cpp : implementation file
//

#include "stdafx.h"
#include "Exam.h"
#include "MyFormView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyFormView

IMPLEMENT_DYNCREATE(CMyFormView, CFormView)

CMyFormView::CMyFormView()
	: CFormView(CMyFormView::IDD)
{
	//{{AFX_DATA_INIT(CMyFormView)
	m_sName = _T("");
	m_sAge = _T("");
	m_sAddress = _T("");
	//}}AFX_DATA_INIT
	m_pList=NULL;
	m_pEdit=NULL;
}

CMyFormView::~CMyFormView()
{
}

void CMyFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyFormView)
	DDX_Text(pDX, IDC_NAME, m_sName);
	DDX_Text(pDX, IDC_AGE, m_sAge);
	DDX_Text(pDX, IDC_ADDRESS, m_sAddress);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyFormView, CFormView)
	//{{AFX_MSG_MAP(CMyFormView)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyFormView diagnostics

#ifdef _DEBUG
void CMyFormView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMyFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyFormView message handlers

void CMyFormView::OnAdd() 
{
    UpdateData(TRUE);
	// 0 为空判断
	m_sName.TrimRight(" ");
	if (m_sName.IsEmpty())
	{
		AfxMessageBox("请输入姓名！");
		return;
	}

	// 1 在右边的列表视图中插入数据
	CListCtrl& theCtrl=m_pList->GetListCtrl();
	int static nItem=0;
	theCtrl.InsertItem(nItem,m_sName);
	theCtrl.SetItemText(nItem,1,m_sAge);
	theCtrl.SetItemText(nItem,2,m_sAddress);
	nItem++;
	// 2 在底部的视图中显示信息
	CString strInfo="添加新学员：";
	strInfo+=m_sName;
	m_pEdit->SetWindowText(strInfo);
	//3 添加用户后，清空控件的数据
	m_sName=m_sAge=m_sAddress="";
	UpdateData(FALSE);


	
}

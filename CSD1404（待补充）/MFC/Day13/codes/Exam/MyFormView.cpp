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
	// 0 Ϊ���ж�
	m_sName.TrimRight(" ");
	if (m_sName.IsEmpty())
	{
		AfxMessageBox("������������");
		return;
	}

	// 1 ���ұߵ��б���ͼ�в�������
	CListCtrl& theCtrl=m_pList->GetListCtrl();
	int static nItem=0;
	theCtrl.InsertItem(nItem,m_sName);
	theCtrl.SetItemText(nItem,1,m_sAge);
	theCtrl.SetItemText(nItem,2,m_sAddress);
	nItem++;
	// 2 �ڵײ�����ͼ����ʾ��Ϣ
	CString strInfo="�����ѧԱ��";
	strInfo+=m_sName;
	m_pEdit->SetWindowText(strInfo);
	//3 ����û�����տؼ�������
	m_sName=m_sAge=m_sAddress="";
	UpdateData(FALSE);


	
}

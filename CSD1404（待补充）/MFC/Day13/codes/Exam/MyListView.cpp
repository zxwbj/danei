// MyListView.cpp : implementation file
//

#include "stdafx.h"
#include "Exam.h"
#include "MyListView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyListView

IMPLEMENT_DYNCREATE(CMyListView, CListView)

CMyListView::CMyListView()
{
}

CMyListView::~CMyListView()
{
}


BEGIN_MESSAGE_MAP(CMyListView, CListView)
	//{{AFX_MSG_MAP(CMyListView)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyListView drawing

void CMyListView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CMyListView diagnostics

#ifdef _DEBUG
void CMyListView::AssertValid() const
{
	CListView::AssertValid();
}

void CMyListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyListView message handlers

int CMyListView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CListView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// 1 ��ȡ��ؿؼ�
	CListCtrl& theCtrl=GetListCtrl();
	// 2 �����
	theCtrl.InsertColumn(0,"����",LVCFMT_LEFT,120);
	theCtrl.InsertColumn(1,"����",LVCFMT_LEFT,120);
	theCtrl.InsertColumn(2,"��ַ",LVCFMT_LEFT,120);
	// 3 ���ÿؼ�����ʾ��ʽΪ����
	theCtrl.ModifyStyle(
		LVS_ICON|LVS_SMALLICON|LVS_LIST,LVS_REPORT);
	
	return 0;
}

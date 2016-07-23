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
	
	// 1 获取相关控件
	CListCtrl& theCtrl=GetListCtrl();
	// 2 添加列
	theCtrl.InsertColumn(0,"姓名",LVCFMT_LEFT,120);
	theCtrl.InsertColumn(1,"年龄",LVCFMT_LEFT,120);
	theCtrl.InsertColumn(2,"地址",LVCFMT_LEFT,120);
	// 3 设置控件的显示方式为报表
	theCtrl.ModifyStyle(
		LVS_ICON|LVS_SMALLICON|LVS_LIST,LVS_REPORT);
	
	return 0;
}

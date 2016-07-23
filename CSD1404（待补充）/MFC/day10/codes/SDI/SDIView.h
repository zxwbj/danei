// SDIView.h : interface of the CSDIView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SDIVIEW_H__EB7D375D_9CBA_44C4_AB77_E39C2F742462__INCLUDED_)
#define AFX_SDIVIEW_H__EB7D375D_9CBA_44C4_AB77_E39C2F742462__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSDIView : public CView
{
protected: // create from serialization only
	CSDIView();
	DECLARE_DYNCREATE(CSDIView)

// Attributes
public:
	CSDIDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSDIView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSDIView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SDIView.cpp
inline CSDIDoc* CSDIView::GetDocument()
   { return (CSDIDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SDIVIEW_H__EB7D375D_9CBA_44C4_AB77_E39C2F742462__INCLUDED_)

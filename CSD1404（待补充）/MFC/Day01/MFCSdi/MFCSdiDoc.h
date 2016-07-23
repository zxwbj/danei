// MFCSdiDoc.h : interface of the CMFCSdiDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCSDIDOC_H__C3B5189A_469F_45DF_A992_5C3CBF0948BF__INCLUDED_)
#define AFX_MFCSDIDOC_H__C3B5189A_469F_45DF_A992_5C3CBF0948BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCSdiDoc : public CDocument
{
protected: // create from serialization only
	CMFCSdiDoc();
	DECLARE_DYNCREATE(CMFCSdiDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCSdiDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFCSdiDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCSdiDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCSDIDOC_H__C3B5189A_469F_45DF_A992_5C3CBF0948BF__INCLUDED_)

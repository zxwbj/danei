// MFCcdcDoc.h : interface of the CMFCcdcDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCCDCDOC_H__016F9B93_3AA6_43BE_904D_2C9DB0AFFB48__INCLUDED_)
#define AFX_MFCCDCDOC_H__016F9B93_3AA6_43BE_904D_2C9DB0AFFB48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCcdcDoc : public CDocument
{
protected: // create from serialization only
	CMFCcdcDoc();
	DECLARE_DYNCREATE(CMFCcdcDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCcdcDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFCcdcDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCcdcDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCCDCDOC_H__016F9B93_3AA6_43BE_904D_2C9DB0AFFB48__INCLUDED_)

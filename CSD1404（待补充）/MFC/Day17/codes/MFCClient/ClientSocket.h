#if !defined(AFX_CLIENTSOCKET_H__0C82EDB5_D790_4612_B187_BE34A189D683__INCLUDED_)
#define AFX_CLIENTSOCKET_H__0C82EDB5_D790_4612_B187_BE34A189D683__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClientSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CClientSocket command target

class CClientSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CClientSocket();
	virtual ~CClientSocket();
    // ��ʼ���ͻ���(����������)
	BOOL InitClient(char* pIP,UINT nPort);
	BOOL SendData(BYTE* pData,long nLen);
	BOOL SendFile(CString sPath);
// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientSocket)
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CClientSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTSOCKET_H__0C82EDB5_D790_4612_B187_BE34A189D683__INCLUDED_)

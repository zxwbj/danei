// UserClient.h: interface for the CUserClient class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_USERCLIENT_H__D0377B07_A019_401C_ADF2_F33308B15564__INCLUDED_)
#define AFX_USERCLIENT_H__D0377B07_A019_401C_ADF2_F33308B15564__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CUserClient  
{
public:
	CUserClient();
	virtual ~CUserClient();

public:
    //��ʼ���ͻ���
    BOOL InitClient( );
    //�㲥����
    BOOL Broadcast( );
    //�˳�����
    BOOL UserQuit( );
    //Chat
    BOOL SendChat( CString strIP, CString strData, 
        BOOL bBroadcast = TRUE );
    //��������
    BOOL SendData( CHAR * pszData, UINT nLen,
        LPCSTR pszIP = NULL );
public:
    SOCKET m_ClientSocket;
};

#endif // !defined(AFX_USERCLIENT_H__D0377B07_A019_401C_ADF2_F33308B15564__INCLUDED_)

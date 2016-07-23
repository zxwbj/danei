// FileClient.h: interface for the CFileClient class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILECLIENT_H__54447FCD_1074_426A_AC66_4DA4B6AA1C21__INCLUDED_)
#define AFX_FILECLIENT_H__54447FCD_1074_426A_AC66_4DA4B6AA1C21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CFileClient  
{
public:
	CFileClient();
	virtual ~CFileClient( );

public:
    //��ʼ���ͻ���
    BOOL InitClient( );
    //���ӷ�����
    BOOL ConnectServer( LPCSTR pszSvrIP );
    //�����ļ�
    BOOL SendFile( LPCTSTR pszFilePath, 
        CProgressCtrl * pwndProgress = NULL );
    //��������
    BOOL SendData( LPVOID pData, DWORD nLen );
public:
    SOCKET m_ClientSocket;
};

#endif // !defined(AFX_FILECLIENT_H__54447FCD_1074_426A_AC66_4DA4B6AA1C21__INCLUDED_)

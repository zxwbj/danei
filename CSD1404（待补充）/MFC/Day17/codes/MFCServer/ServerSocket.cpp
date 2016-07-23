// ServerSocket.cpp : implementation file
//

#include "stdafx.h"
#include "MFCServer.h"
#include "ServerSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CServerSocket

CServerSocket::CServerSocket()
{
}

CServerSocket::~CServerSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CServerSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CServerSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CServerSocket member functions
BOOL CServerSocket::InitServer(UINT nPort)
{
	 // 1 2 �������� 
	if (!Create(nPort))
	{
		return FALSE;
	}
	// 3 ����
	return Listen();
}
//�����ļ���Ϣ�Ľṹ��
typedef struct _tagHeader
{
	char szName[128];//�ļ�����
	long nLen;//�ļ�����
}HEADER,*LPHEADER;

void CServerSocket::OnAccept(int nErrorCode) 
{
	// 4 ���տͻ�������
    CSocket client;
	Accept(client);
	// 5 �����շ�(�����ļ�)
    //5.1 ���Ƚ����ļ���Ϣ(���ƺͳ���)
	HEADER header={0};
    RecvData(client,(BYTE*)&header,sizeof(header));
    //5.2 Ȼ�󣬽����ļ�����
	BYTE *pData=(BYTE*)malloc(header.nLen);
	RecvData(client,pData,header.nLen);
	//5.3 ���ļ����ݱ��浽��������
	CString sPath="c:\\";
	sPath+=header.szName;
	AfxMessageBox(sPath);
	CFile file;
	file.Open(sPath,CFile::modeCreate|CFile::modeWrite);
	file.Write(pData,header.nLen);
	file.Close();
    free(pData);
	// 6 �ر�
	client.Close();
	
	CAsyncSocket::OnAccept(nErrorCode);
}
BOOL CServerSocket::RecvData(CSocket& client,
							 BYTE* pData,long nLen)
{
	BYTE* pTmpData=pData;
	long nLeft=nLen;//��ʾʣ��Ļ�û�н��յ����ݵĳ���
    while (nLeft>0)
    {
        int nRecv=client.Receive(pTmpData,nLeft);
		if (SOCKET_ERROR==nRecv)
		{
			return FALSE;
		}
		nLeft-=nRecv;
        pTmpData+=nRecv; 
    }
	return TRUE;
}

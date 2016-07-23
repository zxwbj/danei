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
	 // 1 2 创建、绑定 
	if (!Create(nPort))
	{
		return FALSE;
	}
	// 3 监听
	return Listen();
}
//定义文件信息的结构体
typedef struct _tagHeader
{
	char szName[128];//文件名称
	long nLen;//文件长度
}HEADER,*LPHEADER;

void CServerSocket::OnAccept(int nErrorCode) 
{
	// 4 接收客户端连接
    CSocket client;
	Accept(client);
	// 5 数据收发(接收文件)
    //5.1 首先接收文件信息(名称和长度)
	HEADER header={0};
    RecvData(client,(BYTE*)&header,sizeof(header));
    //5.2 然后，接收文件数据
	BYTE *pData=(BYTE*)malloc(header.nLen);
	RecvData(client,pData,header.nLen);
	//5.3 将文件数据保存到服务器端
	CString sPath="c:\\";
	sPath+=header.szName;
	AfxMessageBox(sPath);
	CFile file;
	file.Open(sPath,CFile::modeCreate|CFile::modeWrite);
	file.Write(pData,header.nLen);
	file.Close();
    free(pData);
	// 6 关闭
	client.Close();
	
	CAsyncSocket::OnAccept(nErrorCode);
}
BOOL CServerSocket::RecvData(CSocket& client,
							 BYTE* pData,long nLen)
{
	BYTE* pTmpData=pData;
	long nLeft=nLen;//表示剩余的还没有接收的数据的长度
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

// ClientSocket.cpp : implementation file
//

#include "stdafx.h"
#include "MFCClient.h"
#include "ClientSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClientSocket

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CClientSocket, CSocket)
	//{{AFX_MSG_MAP(CClientSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CClientSocket member functions
BOOL CClientSocket::InitClient(char* pIP,UINT nPort)
{
	// 1 创建
	if (!Create())
	{
		return FALSE;
	}
	// 2 连接 
	return Connect(pIP,nPort);
}
//定义文件信息的结构体
typedef struct _tagHeader
{
	char szName[128];//文件名称
	long nLen;//文件长度
}HEADER,*LPHEADER;

BOOL CClientSocket::SendFile(CString sPath)
{
	//3 数据收发(发送文件)
    //3.1 首先发送文件信息
	CFile file;
	file.Open(sPath,CFile::modeRead);
	CString sName=file.GetFileName();
	int nLen=file.GetLength();
	HEADER header={0};
    strcpy(header.szName,sName);
	header.nLen=nLen;
	SendData((BYTE*)&header,sizeof(header));

	//3.2 发送文件数据
    BYTE* pData=(BYTE*)malloc(nLen);
	file.Read(pData,nLen);
	SendData(pData,nLen);
	file.Close();
	free(pData);
	//4 关闭socket
	Close();
	return TRUE;
}
BOOL CClientSocket::SendData(BYTE* pData,long nLen)
{
	BYTE* pTmpData=pData;
	long nLeft=nLen;//剩余还没有发送的数据的长度
	while(nLeft>0)
	{
		int nSend=Send(pTmpData,nLeft);
		if (SOCKET_ERROR==nSend)
		{
			return FALSE;
		}
		nLeft-=nSend;
		pTmpData+=nSend;
	}
	return TRUE;
}

// ClientSocket.cpp: implementation of the CClientSocket class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "VODClient.h"
#include "ClientSocket.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CClientSocket::CClientSocket()
{
  m_hClientSock=NULL;
}

CClientSocket::~CClientSocket()
{
   if (m_hClientSock)
   {
	   closesocket(m_hClientSock);
   }
}
//����socket�����ӷ�����
BOOL CClientSocket::Initialize()
{
	m_hClientSock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if (m_hClientSock==INVALID_SOCKET )
	{
		return FALSE;
	}
    sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
	//��ע��˿ںţ�1024~49151
    addr.sin_port = htons(6789);
    addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    if(0!=connect(m_hClientSock,(sockaddr *)&addr,sizeof(addr)))
	{
       return FALSE;
	}
    return TRUE;
}
//��¼
BOOL CClientSocket::Login(LPCSTR pszName,LPCSTR pszPwd){
    VODLOGIN login = {0};
    strcpy(login.szUserName,pszName);
    strcpy(login.szPassword,pszPwd);

    SendData(VODNETCMD_LOGIN,&login,sizeof(login));
	
    VODHEADER header = {0};
    RecvData(&header,sizeof(header));
    VODLOGINRET loginret = {0};
    RecvData(&loginret,sizeof(loginret));
    return loginret.dwSuccess;
}
//�����ļ�
BOOL CClientSocket::GetMediaData(DWORD videoID,LPCSTR pszFilePath,CString & strFullPath)
{
    MEDIADATA data = {0};
    data.videoID=videoID;
    if(!SendData(VODNETCMD_MEDIADATA,&data,sizeof(data)))
        return FALSE;
    
    VODHEADER header = {0};
    if(!RecvData(&header,sizeof(header)))
	   return FALSE;
    
    MEDIADATARET dataret = {0};
    if(!RecvData(&dataret,sizeof(dataret)))
		return FALSE;
    if (dataret.dwFileLen==0)
    {
        return TRUE;
    }
    strFullPath = pszFilePath;
	strFullPath+=dataret.szFileName;
    //�ж��ļ��Ƿ����
    BOOL bExit=PathFileExists(strFullPath);
   	if (!SendRaw(&bExit,sizeof(bExit)))return FALSE;
    if (bExit)return TRUE;//�ļ����ڣ������ٽ����ļ�����
    CFile file;
    if(!file.Open(strFullPath,CFile::modeCreate|CFile::modeWrite))
		return FALSE;
        
    CHAR szBuff[2000] = {0};
    LONG nLeft = dataret.dwFileLen;
    while(nLeft>0){
        int nRecv = 2000;
        if (nLeft<nRecv)
        {
            nRecv = nLeft;
        }
        RecvData(szBuff,nRecv);
        file.Write(szBuff,nRecv);
        nLeft = nLeft - nRecv;
    }
    file.Close();

    return TRUE;
}
//��ȡ��������
BOOL CClientSocket::GetAllVideoTypes(CString & types)
{
	VODHEADER header={0};
	header.dwVer=1;
	header.dwCmd=VODNETCMD_TYPES;
	header.dwLen=0;
	if (SendRaw(&header,sizeof(header))!=TRUE)
    {
        return FALSE;
    }
	//������������
   
	RecvData(&header,sizeof(header));
	LPSTR pData=types.GetBuffer(header.dwLen);
	RecvData(pData,header.dwLen);
	//�����øú������������ַ����Ľ���
	types.ReleaseBuffer(header.dwLen);
	return TRUE;
}
BOOL CClientSocket::GetVideosByTypeID(DWORD typeID,CString & videos)
{
    GETVIDEOS getVideo;
	getVideo.typdID=typeID;
	if(!SendData(VODNETCMD_GETVIDES,&getVideo,sizeof(getVideo)))
	{
		return FALSE;
	}
	//���ظ����������е�ӰƬ
    VODHEADER header={0};
    RecvData(&header,sizeof(header));
    LPSTR pData=videos.GetBuffer(header.dwLen);
    RecvData(pData,header.dwLen);
   //�����øú������������ַ����Ľ���
	videos.ReleaseBuffer(header.dwLen);
	return TRUE;
}
BOOL CClientSocket::RecvData(LPVOID  pData,UINT nLen){
    INT nLeft = nLen;
    LPSTR pTemp = (LPSTR) pData;
    while(nLeft>0){
        int nRev = recv(m_hClientSock,pTemp,nLeft,0);
        if((nRev==SOCKET_ERROR)||(nRev ==0)) return FALSE;
        pTemp = pTemp + nRev;
        nLeft = nLeft - nRev;
    }
    return TRUE;
}

BOOL CClientSocket::SendData(DWORD dwCmdID,LPVOID pData,UINT nLen )
{
    VODHEADER header = {0};
    header.dwCmd = dwCmdID;
    header.dwLen = nLen;
	//�������ݰ��İ�ͷ
    if (SendRaw(&header,sizeof(header))!=TRUE)
    {
        return FALSE;
    }
	//���͵�¼���ݰ�
    if (SendRaw(pData,nLen) != TRUE)
    {
        return FALSE;
    }
    return TRUE;
}
BOOL CClientSocket::SendRaw(LPVOID  pData,UINT nLen){
    INT nLeft = nLen;
    LPSTR pTemp = (LPSTR) pData;
    while(nLeft>0){
        int nRev = send(m_hClientSock,pTemp,nLeft,0);
        if(nRev ==0) return FALSE;
        pTemp = pTemp + nRev;
        nLeft = nLeft - nRev;
    }
    return TRUE;
}
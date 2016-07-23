// NetClient.h: interface for the CNetClient class.
//
//////////////////////////////////////////////////////////////////////
#include "afxsock.h"
#if !defined(AFX_NETCLIENT_H__EE147879_B044_4D72_B3EB_503590C3B2BD__INCLUDED_)
#define AFX_NETCLIENT_H__EE147879_B044_4D72_B3EB_503590C3B2BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
typedef struct _tagVODHeader{
    DWORD dwVer;
    DWORD dwCmd;
    DWORD dwLen;
}VODHEADER,* LPVODHEADER;

#define VODNETCMD_LOGIN 0x00000001

typedef struct _tagVODLogin{
    CHAR szUserName[128];
    CHAR szPassword[128];
}VODLOGIN,* LPVODLOGIN;

#define VODNETCMD_LOGIN_RET 0x80000001

typedef struct _tagVODLoginRet{
    DWORD dwSuccess;
}VODLOGINRET,* LPVODLOGINRET;

#define  VODNETCMD_TYPES 0x00000002

#define  VODNETCMD_TYPES_RET 0x80000002


#define VODNETCMD_GETVIDES 0x00000003
typedef struct _tagGetVideos
{
	DWORD typdID;
}GETVIDEOS,*LPGETVIDEOS; 

#define VODNETCMD_GETVIDEOS_RET 0x80000003



#define VODNETCMD_MEDIADATA 0x00000006
typedef struct _tagMediaData{
    DWORD videoID;//����ӰƬID
}MEDIADATA,* LPMEDIADATA;
#define VODNETCMD_MEDIADATA_RET 0x80000006
typedef struct _tagMediaDataRet{
    CHAR szFileName[128];//����ӰƬ����Ϣ
    DWORD dwFileLen;//�ļ�����
}MEDIADATARET,* LPMEDIADATARET;
class CNetClient  
{
public:
	CNetClient();
	virtual ~CNetClient();
	//�����̣߳��̺߳���ClientThread
	Initialize( );
	//ҵ���߼���ClientThread������ʵ��
	static DWORD WINAPI ClientThread(LPVOID pParam);
	//����ͻ��˵�¼
	BOOL OnLogin();
	//����ͻ����������Ƶ�ļ�
    BOOL OnMediaData();
    //�������е���Ƶ������Ϣ
	BOOL OnAllVideoTypes();
	//����ָ������ID��������Ƶ��Ϣ
	BOOL OnVideosByTypeID();
    //ԭʼ�������շ�����
	BOOL RecvData(LPVOID  pData,UINT nLen);
    BOOL SendData(DWORD dwCmdID,LPVOID pData,UINT nLen );
    BOOL SendRaw(LPVOID  pData,UINT nLen);	
public:
	SOCKET m_hClientSocket;
};

#endif // !defined(AFX_NETCLIENT_H__EE147879_B044_4D72_B3EB_503590C3B2BD__INCLUDED_)

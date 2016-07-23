 // ClientSocket.h: interface for the CClientSocket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLIENTSOCKET_H__09062176_9994_4C4C_945B_BC1426D64897__INCLUDED_)
#define AFX_CLIENTSOCKET_H__09062176_9994_4C4C_945B_BC1426D64897__INCLUDED_

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



class CClientSocket  
{
public:
	CClientSocket();
	virtual ~CClientSocket();
public:
	//�ͻ��˳�ʼ�������ӷ�����
	BOOL Initialize();
	//1 ��¼
    BOOL Login(LPCSTR pszName,LPCSTR pszPwd);
	//2 ��ȡ������Ƶ������Ϣ
	BOOL GetAllVideoTypes(CString & types);
	//3 ��ȡָ�����͵�������Ƶ����
	BOOL GetVideosByTypeID(DWORD typeID,CString & videos);
	//4 ��ȡָ����ƵID����Ƶ�ļ���������Ƶ�ļ���
    BOOL GetMediaData(DWORD videoID,LPCSTR pszFilePath,CString & strFullPath);
    
	
	//ԭʼ�����ݴ��亯��
    BOOL SendData(DWORD dwCmdID,LPVOID pData,UINT nLen );
	BOOL RecvData(LPVOID  pData,UINT nLen);
	BOOL SendRaw(LPVOID  pData,UINT nLen);
public:
    SOCKET m_hClientSock;
};

#endif // !defined(AFX_CLIENTSOCKET_H__09062176_9994_4C4C_945B_BC1426D64897__INCLUDED_)

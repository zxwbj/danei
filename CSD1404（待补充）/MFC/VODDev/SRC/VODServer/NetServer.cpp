// NetServer.cpp: implementation of the CNetServer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "vodserver.h"
#include "NetServer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNetServer::CNetServer()
{

}

CNetServer::~CNetServer()
{

}
DWORD CNetServer::ServerThread(LPVOID pParam){
    CNetServer * pThis = (CNetServer *)pParam;
	//����socket
    pThis->m_hSockServer = socket(AF_INET,SOCK_STREAM,
        IPPROTO_TCP);
    sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(6789);
    addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	//�󶨵�ַ�Ͷ˿�
    bind(pThis->m_hSockServer,(sockaddr *)&addr,sizeof(addr));
    //����
	listen(pThis->m_hSockServer,0);
     
    while(1){
        sockaddr addrclient = {0};
        int nLen = sizeof(addrclient);
		//���տͻ�������
        SOCKET sock = accept(pThis->m_hSockServer,
            &addrclient,&nLen);
        CNetClient netClient;
        netClient.m_hClientSocket=sock;
		//���ݵĽ�������CNetClient��
        netClient.Initialize();
    }
    
    return 0;
}

void CNetServer::InitServer(){
    DWORD dwThreadID = 0;
    HANDLE hThread = CreateThread(NULL,0,ServerThread,
        this,0,&dwThreadID);
    CloseHandle(hThread);
}
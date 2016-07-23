// SockSvr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <WINSOCK2.H>
#pragma comment(lib,"ws2_32.lib")

// TCP��������
void TCPServer()
{
    //1 ���������׽���
	SOCKET hSockSvr=
		socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if (hSockSvr==INVALID_SOCKET)
	{
		return;
	}

	//2 ��IP��ַ�Ͷ˿�
	SOCKADDR_IN svrAddr={0};
	svrAddr.sin_family=AF_INET;
	svrAddr.sin_port=htons(5678);
	svrAddr.sin_addr.S_un.S_addr=INADDR_ANY;
    bind(hSockSvr,(SOCKADDR*)&svrAddr,sizeof(svrAddr));

    //3 ����
	listen(hSockSvr,5);

    //4 ���տͻ�������
	printf("�ȴ��ͻ�������...\n");
    SOCKADDR_IN clientAddr={0};
	int nLen=sizeof(clientAddr);
	SOCKET hClientSock=
		accept(hSockSvr,(SOCKADDR*)&clientAddr,&nLen);

	//5 �����շ�
	//5.1 �����������Ƚ�������
	char szRecv[256]={0};
	int nRecv=recv(hClientSock,szRecv,256,0);
    //����ͻ�����Ϣ������
	char * ClientIP=inet_ntoa(clientAddr.sin_addr);
	printf("%s:%s\n",ClientIP,szRecv);
	printf("DataLen:%d\n",nRecv);
    //5.2 Ȼ��������
	char szSend[]="Hello,I am a Server";
	send(hClientSock,szSend,strlen(szSend),0);
    //6 �ر��׽���
    closesocket(hClientSock);
	closesocket(hSockSvr);

}

void UDPServer()
{
    //1 �����׽���
	SOCKET hSockSvr=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	if (hSockSvr==INVALID_SOCKET)
	{
		return;
	}
    //2 �󶨵�ַ�Ͷ˿�
	SOCKADDR_IN  svrAddr={0};
	svrAddr.sin_family=AF_INET;
	svrAddr.sin_port=htons(5679);
	svrAddr.sin_addr.S_un.S_addr=INADDR_ANY;
	bind(hSockSvr,(SOCKADDR*)&svrAddr,sizeof(svrAddr));

	//3 �����շ�
	//3.1 ���Ƚ�������
	char szRecv[256]={0};
	SOCKADDR_IN clientAddr={0};
	int nLen=sizeof(clientAddr);
	int nRecv=recvfrom(hSockSvr,szRecv,256,0,
		(SOCKADDR*)&clientAddr,&nLen);
		
	char *IP=inet_ntoa(clientAddr.sin_addr);
    printf("%s:%s\n",IP,szRecv);
	printf("DataLen:%d\n",nRecv);
	//3.2 Ȼ��������
	//4 �ر��׽���
	closesocket(hSockSvr);
}
int main(int argc, char* argv[])
{
	// 1 ��ʼ��socket��
	WSADATA wsa={0};
	WSAStartup(MAKEWORD(2,2),&wsa);

    // 2 �����ͨ��
    //TCPServer();
      UDPServer();
	// 3 ж��socket
	WSACleanup();
	return 0;
}


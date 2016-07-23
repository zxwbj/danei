// SockClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <WINSOCK2.H>
#pragma comment(lib,"ws2_32.lib")

void TCPClient()
{
	//1 ����socket
	SOCKET hSockClient=socket(AF_INET,SOCK_STREAM,0);
	if (hSockClient==INVALID_SOCKET)
	{
		return;
	}
	//2 ����
	SOCKADDR_IN svrAddr={0};
	svrAddr.sin_family=AF_INET;
	svrAddr.sin_port=htons(5678);
	svrAddr.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
	connect(hSockClient,(SOCKADDR*)&svrAddr,
		sizeof(svrAddr));
	//3 �����շ�
	//3.1 �ͻ������ȷ�������
	char szSend[]="Hello,I am a Client!";
	send(hSockClient,szSend,strlen(szSend),0);
	
	//3.2 Ȼ���������
	char szRecv[256]={0};
	int nRecv=recv(hSockClient,szRecv,256,0);
	printf("%s\n",szRecv);
	printf("DataLen:%d\n",nRecv);

	//4 �ر��׽���
	closesocket(hSockClient);
}
void UDPClient()
{
    //1 ����
	SOCKET hSockClient=socket(AF_INET,SOCK_DGRAM,0);
	if (INVALID_SOCKET==hSockClient)
	{
		return;
	}
	//2 �����շ�
	//2.1 �ͻ������ȷ�������
	SOCKADDR_IN  svrAddr={0};
	svrAddr.sin_family=AF_INET;
	svrAddr.sin_port=htons(5679);
	svrAddr.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
	char szSend[]="Hello,I am a UDP Client!";
	sendto(hSockClient,szSend,strlen(szSend),0,
		(SOCKADDR*)&svrAddr,sizeof(svrAddr));
	//2.2 Ȼ��������ݲ����

	//3 �ر��׽���
	closesocket(hSockClient);

}
int main(int argc, char* argv[])
{
	// 1 ��ʼ��socket��
	WSADATA wsa={0};
	WSAStartup(MAKEWORD(2,2),&wsa);
	
    // 2 �����ͨ��
    //TCPClient();
	UDPClient();
	// 3 ж��socket
	WSACleanup();
	return 0;
}


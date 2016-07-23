// SockClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <WINSOCK2.H>
#pragma comment(lib,"ws2_32.lib")

void TCPClient()
{
	//1 创建socket
	SOCKET hSockClient=socket(AF_INET,SOCK_STREAM,0);
	if (hSockClient==INVALID_SOCKET)
	{
		return;
	}
	//2 连接
	SOCKADDR_IN svrAddr={0};
	svrAddr.sin_family=AF_INET;
	svrAddr.sin_port=htons(5678);
	svrAddr.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
	connect(hSockClient,(SOCKADDR*)&svrAddr,
		sizeof(svrAddr));
	//3 数据收发
	//3.1 客户端首先发送数据
	char szSend[]="Hello,I am a Client!";
	send(hSockClient,szSend,strlen(szSend),0);
	
	//3.2 然后接收数据
	char szRecv[256]={0};
	int nRecv=recv(hSockClient,szRecv,256,0);
	printf("%s\n",szRecv);
	printf("DataLen:%d\n",nRecv);

	//4 关闭套接字
	closesocket(hSockClient);
}
void UDPClient()
{
    //1 创建
	SOCKET hSockClient=socket(AF_INET,SOCK_DGRAM,0);
	if (INVALID_SOCKET==hSockClient)
	{
		return;
	}
	//2 数据收发
	//2.1 客户端首先发送数据
	SOCKADDR_IN  svrAddr={0};
	svrAddr.sin_family=AF_INET;
	svrAddr.sin_port=htons(5679);
	svrAddr.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
	char szSend[]="Hello,I am a UDP Client!";
	sendto(hSockClient,szSend,strlen(szSend),0,
		(SOCKADDR*)&svrAddr,sizeof(svrAddr));
	//2.2 然后接收数据并输出

	//3 关闭套接字
	closesocket(hSockClient);

}
int main(int argc, char* argv[])
{
	// 1 初始化socket库
	WSADATA wsa={0};
	WSAStartup(MAKEWORD(2,2),&wsa);
	
    // 2 具体的通信
    //TCPClient();
	UDPClient();
	// 3 卸载socket
	WSACleanup();
	return 0;
}


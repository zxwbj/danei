// SockSvr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <WINSOCK2.H>
#pragma comment(lib,"ws2_32.lib")

// TCP服务器端
void TCPServer()
{
    //1 创建监听套接字
	SOCKET hSockSvr=
		socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if (hSockSvr==INVALID_SOCKET)
	{
		return;
	}

	//2 绑定IP地址和端口
	SOCKADDR_IN svrAddr={0};
	svrAddr.sin_family=AF_INET;
	svrAddr.sin_port=htons(5678);
	svrAddr.sin_addr.S_un.S_addr=INADDR_ANY;
    bind(hSockSvr,(SOCKADDR*)&svrAddr,sizeof(svrAddr));

    //3 监听
	listen(hSockSvr,5);

    //4 接收客户端连接
	printf("等待客户端连接...\n");
    SOCKADDR_IN clientAddr={0};
	int nLen=sizeof(clientAddr);
	SOCKET hClientSock=
		accept(hSockSvr,(SOCKADDR*)&clientAddr,&nLen);

	//5 数据收发
	//5.1 服务器端首先接收数据
	char szRecv[256]={0};
	int nRecv=recv(hClientSock,szRecv,256,0);
    //输出客户端信息和数据
	char * ClientIP=inet_ntoa(clientAddr.sin_addr);
	printf("%s:%s\n",ClientIP,szRecv);
	printf("DataLen:%d\n",nRecv);
    //5.2 然后发送数据
	char szSend[]="Hello,I am a Server";
	send(hClientSock,szSend,strlen(szSend),0);
    //6 关闭套接字
    closesocket(hClientSock);
	closesocket(hSockSvr);

}

void UDPServer()
{
    //1 创建套接字
	SOCKET hSockSvr=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	if (hSockSvr==INVALID_SOCKET)
	{
		return;
	}
    //2 绑定地址和端口
	SOCKADDR_IN  svrAddr={0};
	svrAddr.sin_family=AF_INET;
	svrAddr.sin_port=htons(5679);
	svrAddr.sin_addr.S_un.S_addr=INADDR_ANY;
	bind(hSockSvr,(SOCKADDR*)&svrAddr,sizeof(svrAddr));

	//3 数据收发
	//3.1 首先接收数据
	char szRecv[256]={0};
	SOCKADDR_IN clientAddr={0};
	int nLen=sizeof(clientAddr);
	int nRecv=recvfrom(hSockSvr,szRecv,256,0,
		(SOCKADDR*)&clientAddr,&nLen);
		
	char *IP=inet_ntoa(clientAddr.sin_addr);
    printf("%s:%s\n",IP,szRecv);
	printf("DataLen:%d\n",nRecv);
	//3.2 然后发送数据
	//4 关闭套接字
	closesocket(hSockSvr);
}
int main(int argc, char* argv[])
{
	// 1 初始化socket库
	WSADATA wsa={0};
	WSAStartup(MAKEWORD(2,2),&wsa);

    // 2 具体的通信
    //TCPServer();
      UDPServer();
	// 3 卸载socket
	WSACleanup();
	return 0;
}


#include "stdafx.h"
#include "windows.h"
#include "stdio.h"
HANDLE g_hMutex = 0;//接收互斥句柄
DWORD CALLBACK TestProc1( LPVOID pParam )
{
	while( 1 )
	{
		WaitForSingleObject( g_hMutex, INFINITE );
		//如果g_hMutex有信号，通过阻塞同时将g_hMutex置为
		//无信号。
		//如果g_hMutex无信号，阻塞
		printf( "********\n" );
		Sleep( 1000 );
		ReleaseMutex( g_hMutex );
	}
	return 0;
}
DWORD CALLBACK TestProc2( LPVOID pParam )
{
	while( 1 )
	{
		WaitForSingleObject( g_hMutex, INFINITE );
		printf( "--------\n" );
		Sleep( 1000 );
		ReleaseMutex( g_hMutex );
	}
	return 0;
}
int main(int argc, char* argv[])
{
	g_hMutex = CreateMutex( NULL, FALSE, NULL );
	DWORD nID = 0;
	HANDLE hThread[2] = { 0 };
	hThread[0] = CreateThread( NULL, 0, TestProc1, NULL,
							0, &nID );
	hThread[1] = CreateThread( NULL, 0, TestProc2, NULL,
							0, &nID );
	WaitForMultipleObjects( 2, hThread, TRUE, INFINITE );
	CloseHandle( hThread[0] );
	CloseHandle( hThread[1] );
	CloseHandle( g_hMutex );
	return 0;
}

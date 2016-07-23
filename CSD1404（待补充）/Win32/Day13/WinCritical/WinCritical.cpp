#include "stdafx.h"
#include "windows.h"
#include "stdio.h"
CRITICAL_SECTION cs = { 0 };//临界区变量
DWORD CALLBACK TestProc1( LPVOID pParam )
{
	while( 1 )
	{
		EnterCriticalSection( &cs );
		printf( "********\n" );
		Sleep( 1000 );
		LeaveCriticalSection( &cs );
	}
	return 0;
}
DWORD CALLBACK TestProc2( LPVOID pParam )
{
	while( 1 )
	{
		EnterCriticalSection( &cs );
		printf( "--------\n" );
		Sleep( 1000 );
		LeaveCriticalSection( &cs );
	}
	return 0;
}
int main(int argc, char* argv[])
{
	InitializeCriticalSection( &cs );//初始化
	DWORD nID = 0;
	HANDLE hThread[2] = { 0 };
	hThread[0] = CreateThread( NULL, 0, TestProc1, NULL,
								0, &nID );
	hThread[1] = CreateThread( NULL, 0, TestProc2, NULL,
								0, &nID );
	WaitForMultipleObjects( 2, hThread, TRUE, INFINITE );
	CloseHandle( hThread[0] );
	CloseHandle( hThread[1] );
	DeleteCriticalSection( &cs );//删除临界区
	return 0;
}

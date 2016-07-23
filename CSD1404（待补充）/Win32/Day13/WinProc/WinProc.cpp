#include "stdafx.h"
#include "windows.h"
#include "stdio.h"
void Env( )
{
	char *pszEnv = (char*)GetEnvironmentStrings( );
	char *pszText = pszEnv;
	while( pszText[0] )
	{
		printf( "%s\n", pszText );
		pszText = pszText + strlen(pszText) + 1;
	}
	FreeEnvironmentStrings( pszEnv );
}
void Variable( )
{
	SetEnvironmentVariable( "zjw", "good" );
	char szVar[256] = { 0 };
	GetEnvironmentVariable( "zjw", szVar, 256 );
	printf( "%s\n", szVar );
}
void ProcInfo( )
{
	DWORD nID = GetCurrentProcessId( );
	HANDLE hProc = GetCurrentProcess( );
	printf( "ID=%d,hProc=%d\n", nID, hProc );
}
void Proc( )
{
	STARTUPINFO si = { 0 };
	PROCESS_INFORMATION pi = { 0 };
	CreateProcess( "C:/WINDOWS/system32/calc.exe",
				"", NULL, NULL, FALSE, 0, 
				NULL, NULL, &si, &pi );
	printf( "ID=%d,¾ä±ú=%d\n", pi.dwProcessId,
							pi.hProcess );
	WaitForSingleObject( pi.hProcess, INFINITE );
	printf( "wait over!!!\n" );
}
void Kill( )
{
	HANDLE hProc = OpenProcess( 
					PROCESS_ALL_ACCESS, FALSE, 888 );
	TerminateProcess( hProc, 123 );
}
int main(int argc, char* argv[])
{
//	Env( );
//	Variable( );
//	ProcInfo( );
	Proc( );
//	Kill( );
	return 0;
}

#include "stdafx.h"
#include "stdio.h"
#include "windows.h"
void Create( )
{
	HANDLE hFile = CreateFile( 
				"c:/file.txt", GENERIC_WRITE, 
				FILE_SHARE_READ, NULL, CREATE_ALWAYS,
				FILE_ATTRIBUTE_NORMAL, NULL );
	CloseHandle( hFile );
}
void Write( )
{
	HANDLE hFile = CreateFile( "c:/file.txt", 
						GENERIC_WRITE, FILE_SHARE_READ,
						NULL, OPEN_ALWAYS, 
						FILE_ATTRIBUTE_NORMAL, NULL );
	char szText[] = "hello txt";
	DWORD nCount = 0;
	WriteFile( hFile, szText, strlen(szText), &nCount,
				NULL );
	printf( "׼��д�볤��:%d,ʵ��д�볤��:%d\n",
						strlen(szText), nCount );
	CloseHandle( hFile );
}
void Read( )
{
	HANDLE hFile = CreateFile( "c:/file.txt", 
				GENERIC_READ, FILE_SHARE_READ, NULL,
				OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	DWORD nHight = 0;
	DWORD nLow = GetFileSize( hFile, &nHight );

	char szText[256] = { 0 };
	DWORD nCount = 0;
	ReadFile( hFile, szText, nLow, &nCount, NULL );
	printf( "׼����ȡ:%d,ʵ�ʶ�ȡ:%d,����:%s\n",
					nLow, nCount, szText );
	CloseHandle( hFile );
}
int main(int argc, char* argv[])
{
//	Create( );
//	Write( );
	Read( );
	return 0;
}

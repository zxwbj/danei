#include "stdafx.h"
#include "windows.h"
#include "stdio.h"

int main(int argc, char* argv[])
{
	HANDLE hFile = CreateFile( "c:/map.dat", 
					GENERIC_READ|GENERIC_WRITE, 
					FILE_SHARE_READ, NULL, CREATE_ALWAYS,
					FILE_ATTRIBUTE_NORMAL, NULL );
	HANDLE hMap = CreateFileMapping( 
						NULL, NULL, PAGE_READWRITE,
						0, 1024*1024, "zjw" );
	//�����һ������ΪNULL, ����1M�ڴ�
	//�����һ������ΪhFile����Ӳ���ļ�����1M��С
	char *pszText = (char*)MapViewOfFile( 
				hMap, FILE_MAP_ALL_ACCESS, 0, 64*1024, 0 );
	//�� �����̵�ַ �� �ڴ�/Ӳ���ļ�  ����ӳ���ϵ
	strcpy( pszText, "hello map" );
//	printf( "%s\n", pszText );
	UnmapViewOfFile( pszText );
	getchar( );
	CloseHandle( hMap );//һ���رվ�û�ˡ�
	CloseHandle( hFile );
	return 0;
}

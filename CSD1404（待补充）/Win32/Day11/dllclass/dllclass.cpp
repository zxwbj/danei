
#define DLLCLASS_EXPORT
#include "dllclass.h"
#include "stdio.h"
#include "windows.h"
BOOL CALLBACK DllMain( HINSTANCE hDll,
				DWORD fdwReason, LPVOID pVoid )
{
	switch( fdwReason )
	{
	case DLL_PROCESS_ATTACH:
		printf( "Loading......\n" );//��ʼ������
		break;
	case DLL_PROCESS_DETACH:
		printf( "UnLoading....\n" );//�ƺ���
		break;
	}
	return TRUE;
}
int CMath::Add( int add1, int add2 )
{
	return add1 + add2;
}
int CMath::Sub( int sub1, int sub2 )
{
	return sub1 - sub2;
}
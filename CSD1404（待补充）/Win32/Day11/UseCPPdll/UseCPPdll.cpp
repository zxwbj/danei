#include "stdio.h"
_declspec(dllimport)int CPPdll_add( int add1, int add2 );
_declspec(dllimport)int CPPdll_sub( int sub1, int sub2 );

#pragma comment( lib, "../lib/CPPdll.lib" )
/*֪ͨ����������ץ�����ı�� �� ����dll�ļ���˭*/
int main( )
{
	int sum = CPPdll_add( 5, 3 ); //1
	int sub = CPPdll_sub( 5, 3 ); //2
	printf( "sum=%d,sub=%d\n", sum, sub );
	return 0;
}
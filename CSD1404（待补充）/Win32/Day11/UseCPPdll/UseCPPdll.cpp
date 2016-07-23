#include "stdio.h"
_declspec(dllimport)int CPPdll_add( int add1, int add2 );
_declspec(dllimport)int CPPdll_sub( int sub1, int sub2 );

#pragma comment( lib, "../lib/CPPdll.lib" )
/*通知链接器到哪抓函数的编号 和 配套dll文件是谁*/
int main( )
{
	int sum = CPPdll_add( 5, 3 ); //1
	int sub = CPPdll_sub( 5, 3 ); //2
	printf( "sum=%d,sub=%d\n", sum, sub );
	return 0;
}
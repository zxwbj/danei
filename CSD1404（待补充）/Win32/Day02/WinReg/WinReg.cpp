#include "stdafx.h"
HINSTANCE g_hInstance = 0;//���յ�ǰ����ʵ�����
void SysReg( )
{
	//����Ҫע��
	HWND hWnd = CreateWindow( "EDIT", "OK", 
						WS_OVERLAPPEDWINDOW, 
						100, 100, 500, 500, NULL, NULL, g_hInstance,
						NULL );
	ShowWindow( hWnd, SW_SHOW );
	UpdateWindow( hWnd );
	MSG nMsg = { 0 };
	while( GetMessage(&nMsg, NULL, 0, 0) )
	{
		TranslateMessage( &nMsg );
		DispatchMessage( &nMsg );
	}
	
}
void AppReg( )
{
	WNDCLASSEX wce = { 0 };
	wce.cbSize = sizeof( wce );
	wce.cbClsExtra = 0;
	wce.cbWndExtra = 0;
	wce.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wce.hCursor = NULL;
	wce.hIcon = NULL;
	wce.hIconSm = NULL;
	wce.hInstance = g_hInstance;/************************/
	wce.lpfnWndProc = DefWindowProc;
	wce.lpszClassName = "Main";/************************/
	wce.lpszMenuName = NULL;
	wce.style = CS_HREDRAW | CS_VREDRAW;
	ATOM nAtom = RegisterClassEx( &wce );
	if( nAtom==0 )
	{
		MessageBox( NULL, "ע��ʧ��", "Infor", MB_OK );
		return;
	}
	HWND hWnd = CreateWindow( "Main", "window",
								WS_OVERLAPPEDWINDOW, 100, 100, 500, 500,
								NULL, NULL, g_hInstance, NULL );
	ShowWindow( hWnd, SW_SHOW );
	UpdateWindow( hWnd );
	MSG nMsg = { 0 };
	while( GetMessage( &nMsg, NULL, 0, 0 ) )
	{
		TranslateMessage( &nMsg );
		DispatchMessage( &nMsg );
	}
}
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	g_hInstance = hInstance;
//	SysReg( );
	AppReg( );
	return 0;
}




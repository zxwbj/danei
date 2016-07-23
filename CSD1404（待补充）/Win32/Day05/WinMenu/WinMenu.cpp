#include "stdafx.h"
HINSTANCE g_hInstance = 0;//接收当前程序实例句柄
void OnCreate( HWND hWnd )
{
	HMENU hMain = CreateMenu( );

	HMENU hFile = CreatePopupMenu( );
	AppendMenu( hFile, MF_STRING|MF_CHECKED, 1003, "新建" );
	AppendMenu( hFile, MF_SEPARATOR, 0, "" );
	AppendMenu( hFile, MF_STRING|MF_MENUBARBREAK, 1004, "退出" );

	HMENU hHelp = CreatePopupMenu( );
	AppendMenu( hHelp, MF_STRING|MF_GRAYED, 1005, "关于" );

	AppendMenu( hMain, MF_POPUP, (UINT)hFile, "文件" );
	AppendMenu( hMain, MF_POPUP, (UINT)hHelp, "帮助" );
	SetMenu( hWnd, hMain );
}
void OnCommand( HWND hWnd, WPARAM wParam )
{
	switch( LOWORD(wParam) )
	{
		case 1003:
			MessageBox( hWnd, "新建被点击", "Infor", MB_OK );
			break;
		case 1004:
			MessageBox( hWnd, "退出被点击", "Infor", MB_OK );
			break;
		case 1005:
			MessageBox( hWnd, "关于被点击", "Infor", MB_OK );
			break;
	}
}
//窗口处理函数
LRESULT CALLBACK WndProc( HWND hWnd, UINT msg, 
												 WPARAM wParam, LPARAM lParam )
{
	switch( msg )
	{
		case WM_COMMAND:
			OnCommand( hWnd, wParam );
			break;
		case WM_CREATE:
			OnCreate( hWnd );
			break;
		case WM_DESTROY:
			PostQuitMessage( 0 );
			break;
	}
	return DefWindowProc( hWnd, msg, wParam, lParam );
}
//注册窗口类
BOOL Register( LPSTR lpClassName, WNDPROC wndProc )
{
	WNDCLASSEX wce = { 0 };
	wce.cbSize = sizeof( wce );
	wce.cbClsExtra = 0;
	wce.cbWndExtra = 0;
	wce.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wce.hCursor = NULL;
	wce.hIcon = NULL;
	wce.hIconSm = NULL;
	wce.hInstance = g_hInstance;
	wce.lpfnWndProc = wndProc;
	wce.lpszClassName = lpClassName;
	wce.lpszMenuName = NULL;
	wce.style = CS_HREDRAW | CS_VREDRAW;
	ATOM nAtom = RegisterClassEx( &wce );
	if( nAtom==0 )
		return FALSE;
	return TRUE;
}
//创建主窗口
HWND CreateMain( LPSTR lpClassName, LPSTR lpWndName )
{
	HWND hWnd = CreateWindowEx( 0, lpClassName, lpWndName,
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT, 
		CW_USEDEFAULT, NULL, NULL, g_hInstance,
		NULL );
	return hWnd;
}
//显示窗口
void Display( HWND hWnd )
{
	ShowWindow( hWnd, SW_SHOW );
	UpdateWindow( hWnd );
}
//消息循环
void Message( )
{
	MSG nMsg = { 0 };
	while( GetMessage(&nMsg, NULL, 0, 0) )
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
	Register( "Main", WndProc );
	HWND hWnd = CreateMain( "Main", "window" );
	Display( hWnd );
	Message( );
	return 0;
}




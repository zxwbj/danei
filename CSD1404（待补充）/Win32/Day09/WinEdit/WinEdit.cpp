#include "stdafx.h"
HINSTANCE g_hInstance = 0;//接收当前程序实例句柄
void OnCreate( HWND hWnd )
{
	CreateWindowEx( WS_EX_CLIENTEDGE, "EDIT", "hello", 
			WS_CHILD|WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL|
			ES_MULTILINE|ES_AUTOVSCROLL|WS_HSCROLL|
			WS_VSCROLL,
			0, 0, 200, 200, hWnd, (HMENU)1001, 
			g_hInstance, NULL );
	/*
	ES_PASSWORD - 只适用于单行编辑框
	ES_NUMBER - 限制只能输入数字键，不能输入字符键
	*/
}
//窗口处理函数
LRESULT CALLBACK WndProc( HWND hWnd, UINT msg, 
						 WPARAM wParam, LPARAM lParam )
{
	switch( msg )
	{
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
	char szTitle[256] = { 0 };
	HWND hWnd = CreateMain( "Main", "window" );
	Display( hWnd );
	Message( );
	return 0;
}




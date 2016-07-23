#include "stdafx.h"
#include "stdio.h"
HINSTANCE g_hInstance = 0;//接收当前程序实例句柄
HANDLE g_hOutput = 0;
void OnPaint( HWND hWnd )
{
	char szText[] = "WM_PAINT\n";
//	WriteConsole( g_hOutput, szText, strlen(szText),
	//								NULL, NULL );
	PAINTSTRUCT ps = { 0 };
	HDC hdc = BeginPaint( hWnd, &ps );
	TextOut( hdc, 100, 100, "hello", strlen("hello") );
	EndPaint( hWnd, &ps );
	/*以上四句必须放在WM_PAINT消息的处理中调用*/
}
void OnKeyDown( HWND hWnd, WPARAM wParam )
{
	char szText[256] = { 0 };
	sprintf( szText, "WM_KEYDOWN:%08X\n", wParam );
	WriteConsole( g_hOutput, szText, strlen(szText),
									NULL, NULL );
}
void OnKeyUp( HWND hWnd, WPARAM wParam )
{
	char szText[256] = { 0 };
	sprintf( szText, "WM_KEYUP:%08X\n", wParam );
	WriteConsole( g_hOutput, szText, strlen(szText),
									NULL, NULL );
}
//窗口处理函数
LRESULT CALLBACK WndProc( HWND hWnd, UINT msg, 
												 WPARAM wParam, LPARAM lParam )
{
	switch( msg )
	{
		case WM_KEYDOWN:
			OnKeyDown( hWnd, wParam );
			break;
		case WM_KEYUP:
			OnKeyUp( hWnd, wParam );
			break;
		case WM_LBUTTONDOWN:
			InvalidateRect( hWnd, NULL, TRUE );
			break;
		case WM_PAINT:
			OnPaint( hWnd );
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
	AllocConsole( );
	g_hOutput = GetStdHandle( STD_OUTPUT_HANDLE );
	g_hInstance = hInstance;
	Register( "Main", WndProc );
	HWND hWnd = CreateMain( "Main", "window" );
	Display( hWnd );
	Message( );
	return 0;
}




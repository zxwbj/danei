#include "stdafx.h"
#include "stdio.h"
HINSTANCE g_hInstance = 0;//接收当前程序实例句柄
HANDLE g_hOutput = 0;
int g_xPos = 100;
int g_yPos = 100;
void OnLButtonDown(HWND hWnd,WPARAM wParam,LPARAM lParam)
{
	char szText[256] = { 0 };
	sprintf( szText,
			"WM_LBUTTONDOWN: 按键状态:%08X, x=%d,y=%d\n",
			wParam, LOWORD(lParam), HIWORD(lParam) );
	WriteConsole( g_hOutput, szText, strlen(szText),
									NULL, NULL );
}
void OnLButtonUp( HWND hWnd,WPARAM wParam,LPARAM lParam)
{
	char szText[256] = { 0 };
	sprintf( szText,
				"WM_LBUTTONUP:按键状态:%08X, x=%d,y=%d\n",
				wParam, LOWORD(lParam), HIWORD(lParam) );
	WriteConsole( g_hOutput, szText, strlen(szText),
					NULL, NULL );
}
void OnMouseMove( HWND hWnd, LPARAM lParam )
{
	char szText[256] = { 0 };
	sprintf( szText, "WM_MOUSEMOVE:x=%d,y=%d\n",
							LOWORD(lParam), HIWORD(lParam) );
//	WriteConsole( g_hOutput, szText, strlen(szText),
//								NULL, NULL );
	g_xPos = LOWORD(lParam);
	g_yPos = HIWORD(lParam);
	InvalidateRect( hWnd, NULL, FALSE );
}
void OnPaint( HWND hWnd )
{
	PAINTSTRUCT ps = { 0 };
	HDC hdc = BeginPaint( hWnd, &ps );
	TextOut( hdc, g_xPos, g_yPos, "hello", 5 );
	EndPaint( hWnd, &ps );
}
void OnLButtonDblClk( HWND hWnd )
{
	char szText[] = "WM_LBUTTONDBLCLK\n";
	WriteConsole( g_hOutput, szText, strlen(szText),
									NULL, NULL );
}
void OnMouseWheel( HWND hWnd, WPARAM wParam )
{
	short nDelta = HIWORD(wParam);//偏移量
	char szText[256] = { 0 };
	sprintf( szText, "偏移量:%d\n", nDelta );
	WriteConsole( g_hOutput, szText, strlen(szText),
								NULL, NULL );
}
//窗口处理函数
LRESULT CALLBACK WndProc( HWND hWnd, UINT msg, 
												 WPARAM wParam, LPARAM lParam )
{
	switch( msg )
	{
		case WM_MOUSEWHEEL:
			OnMouseWheel( hWnd, wParam );
			break;
		case WM_LBUTTONDBLCLK:
			OnLButtonDblClk( hWnd );
			break;
		case WM_PAINT:
			OnPaint( hWnd );
			break;
		case WM_MOUSEMOVE:
			OnMouseMove( hWnd, lParam );
			break;
		case WM_LBUTTONDOWN:
			OnLButtonDown( hWnd, wParam, lParam );
			break;
		case WM_LBUTTONUP:
			OnLButtonUp( hWnd, wParam, lParam );
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
	wce.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
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




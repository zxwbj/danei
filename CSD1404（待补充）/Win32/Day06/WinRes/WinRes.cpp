#include "stdafx.h"
#include "resource.h"
HINSTANCE g_hInstance = 0;//接收当前程序实例句柄
void OnCommand( HWND hWnd, WPARAM wParam )
{
	switch( LOWORD(wParam) )
	{
		case ID_NEW://40001
			MessageBox( hWnd, "新建被点击", "Infor", MB_OK );
			break;
	}
}
void OnPaint( HWND hWnd )
{
	PAINTSTRUCT ps = { 0 };
	HDC hdc = BeginPaint( hWnd, &ps );
	HICON hIcon = LoadIcon( g_hInstance, 
									MAKEINTRESOURCE(IDI_ICON1) );
	DrawIcon( hdc, 100, 100, hIcon );
	EndPaint( hWnd, &ps );
}
//窗口处理函数
LRESULT CALLBACK WndProc( HWND hWnd, UINT msg, 
												 WPARAM wParam, LPARAM lParam )
{
	switch( msg )
	{
		case WM_SETCURSOR:
			if( LOWORD(lParam)==HTCLIENT )
			{
				HCURSOR hBall = LoadCursor( g_hInstance,
										MAKEINTRESOURCE(IDC_CURSOR2) );
				SetCursor( hBall );
				return 0;
			}else{
				//什么都不写
			}
			break;
		case WM_PAINT:
			OnPaint( hWnd );
			break;
		case WM_COMMAND:
			OnCommand( hWnd, wParam );
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
	wce.hCursor = LoadCursor( g_hInstance,
									MAKEINTRESOURCE(IDC_CURSOR1) );
	wce.hIcon = LoadIcon( g_hInstance,
										MAKEINTRESOURCE(IDI_ICON1) );
	wce.hIconSm = LoadIcon( g_hInstance,
										MAKEINTRESOURCE(IDI_ICON2) );
	wce.hInstance = g_hInstance;
	wce.lpfnWndProc = wndProc;
	wce.lpszClassName = lpClassName;
	wce.lpszMenuName = NULL;//MAKEINTRESOURCE(IDR_MENU1);
	wce.style = CS_HREDRAW | CS_VREDRAW;
	ATOM nAtom = RegisterClassEx( &wce );
	if( nAtom==0 )
		return FALSE;
	return TRUE;
}
//创建主窗口
HWND CreateMain( LPSTR lpClassName, LPSTR lpWndName )
{
	HMENU hMenu = LoadMenu( g_hInstance,
									MAKEINTRESOURCE(IDR_MENU1) );
	HWND hWnd = CreateWindowEx( 0, lpClassName, lpWndName,
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT, 
		CW_USEDEFAULT, NULL, hMenu, g_hInstance,
		NULL );
	HICON hIcon = LoadIcon( g_hInstance,
									MAKEINTRESOURCE(IDI_ICON1) );
	SendMessage( hWnd,
					WM_SETICON, ICON_SMALL, (LPARAM)hIcon );

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




#include "stdafx.h"
HINSTANCE g_hInstance = 0;//接收当前程序实例句柄
void OnCreate( HWND hWnd )
{
	HMENU hSys = GetSystemMenu( hWnd, FALSE );
	for( int i=0; i<6; i++ )
	{
		DeleteMenu( hSys, 0, MF_BYPOSITION );
	}
	AppendMenu( hSys, MF_SEPARATOR, 0, "" );
	AppendMenu( hSys, MF_STRING, 1001, "我的菜单项" );
}
void OnSysCommand( HWND hWnd, WPARAM wParam )
{
	switch( LOWORD(wParam) )
	{
		case 1001:
			MessageBox( hWnd, "我的菜单项被点击", "Infor",
										MB_OK );
			break;
	}
}
void OnRButtonUp( HWND hWnd, LPARAM lParam )
{
/*	HMENU hPopup = CreatePopupMenu( );
	AppendMenu( hPopup, MF_STRING, 1002, "新建" );
	AppendMenu( hPopup, MF_SEPARATOR, 0, "" );
	AppendMenu( hPopup, MF_STRING, 1003, "退出" );
	POINT pt = { 0 };
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
	ClientToScreen( hWnd, &pt );

	BOOL nRet = TrackPopupMenu( hPopup, 
		TPM_CENTERALIGN|TPM_VCENTERALIGN|TPM_RETURNCMD, 
		pt.x, pt.y, 0, hWnd, NULL );
	switch( nRet )
	{
		case 1002:
			MessageBox( hWnd, 
				"没发出WM_COMMAND消息，处理了新建被点击", "Infor",
				MB_OK );
			break;
		case 1003:
			MessageBox( hWnd, 
				"没发出WM_COMMAND消息，处理了退出被点击", "Infor",
				MB_OK );
			break;
	}*/
}
void OnCommand( HWND hWnd, WPARAM wParam )
{
	switch( LOWORD(wParam) )
	{
		case 1002:
			MessageBox( hWnd, "新建被点击", "Infor", MB_OK );
			break;
		case 1003:
			MessageBox( hWnd, "退出被点击", "Infor", MB_OK );
			break;
	}
}
void OnContextMenu( HWND hWnd, LPARAM lParam )
{
	HMENU hPopup = CreatePopupMenu( );
	AppendMenu( hPopup, MF_STRING, 1002, "新建" );
	AppendMenu( hPopup, MF_SEPARATOR, 0, "" );
	AppendMenu( hPopup, MF_STRING, 1003, "退出" );
	POINT pt = { 0 };
	pt.x = LOWORD(lParam);
	pt.y = HIWORD(lParam);
//	ClientToScreen( hWnd, &pt );//专业人士，无需转换
	
	BOOL nRet = TrackPopupMenu( hPopup, 
		TPM_CENTERALIGN|TPM_VCENTERALIGN|TPM_RETURNCMD, 
		pt.x, pt.y, 0, hWnd, NULL );
	switch( nRet )
	{
		case 1002:
			MessageBox( hWnd, 
				"没发出WM_COMMAND消息，处理了新建被点击", "Infor",
				MB_OK );
			break;
		case 1003:
			MessageBox( hWnd, 
				"没发出WM_COMMAND消息，处理了退出被点击", "Infor",
				MB_OK );
			break;
	}
}
//窗口处理函数
LRESULT CALLBACK WndProc( HWND hWnd, UINT msg, 
												 WPARAM wParam, LPARAM lParam )
{
	switch( msg )
	{
		case WM_CONTEXTMENU:
			OnContextMenu( hWnd, lParam );
			break;
		case WM_COMMAND:
			OnCommand( hWnd, wParam );
			break;
		case WM_RBUTTONUP:
			OnRButtonUp( hWnd, lParam );
			break;
		case WM_SYSCOMMAND:
			OnSysCommand( hWnd, wParam );
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




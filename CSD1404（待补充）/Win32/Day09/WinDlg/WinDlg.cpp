#include "stdafx.h"
#include "resource.h"
HINSTANCE g_hInstance = 0;//接收当前程序实例句柄
int CALLBACK DlgProc( HWND hwndlg, UINT msg, 
					 WPARAM wParam, LPARAM lParam )
{
	switch( msg )
	{
	case WM_INITDIALOG:
		MessageBox(hwndlg,"WM_INITDIALOG","Infor",MB_OK);
		break;
	case WM_CREATE:
		MessageBox(hwndlg,"WM_CREATE","Infor",MB_OK);
		break;
	case WM_SYSCOMMAND:
		if( wParam==SC_CLOSE )
		{
			EndDialog( hwndlg, 1001 );//销毁模式对话框
//			DestroyWindow( hwndlg );
			return TRUE;
		}		
		break;
	}
	return FALSE;//将消息交给真正对话框处理函数做默认处理
}
void OnModel( HWND hWnd )
{
	int nRet = DialogBox( g_hInstance, 
		MAKEINTRESOURCE(IDD_DIALOG1), hWnd, DlgProc );
	if( nRet == 1001 )
	{
		MessageBox( hWnd, "successful", "Infor", MB_OK );
	}
}
void OnCommand( HWND hWnd, WPARAM wParam )
{
	switch( LOWORD(wParam) )
	{
	case ID_MODEL:
		OnModel( hWnd );//创建模式对话框
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
	wce.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
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




#include "stdafx.h"
HINSTANCE g_hInstance = 0;//���յ�ǰ����ʵ�����
void OnCreate( HWND hWnd )
{
	HMENU hMain = CreateMenu( );

	HMENU hFile = CreatePopupMenu( );
	AppendMenu( hFile, MF_STRING|MF_CHECKED, 1003, "�½�" );
	AppendMenu( hFile, MF_SEPARATOR, 0, "" );
	AppendMenu( hFile, MF_STRING|MF_MENUBARBREAK, 1004, "�˳�" );

	HMENU hHelp = CreatePopupMenu( );
	AppendMenu( hHelp, MF_STRING|MF_GRAYED, 1005, "����" );

	AppendMenu( hMain, MF_POPUP, (UINT)hFile, "�ļ�" );
	AppendMenu( hMain, MF_POPUP, (UINT)hHelp, "����" );
	SetMenu( hWnd, hMain );
}
void OnCommand( HWND hWnd, WPARAM wParam )
{
	switch( LOWORD(wParam) )
	{
		case 1003:
			MessageBox( hWnd, "�½������", "Infor", MB_OK );
			break;
		case 1004:
			MessageBox( hWnd, "�˳������", "Infor", MB_OK );
			break;
		case 1005:
			MessageBox( hWnd, "���ڱ����", "Infor", MB_OK );
			break;
	}
}
//���ڴ�����
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
//ע�ᴰ����
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
//����������
HWND CreateMain( LPSTR lpClassName, LPSTR lpWndName )
{
	HWND hWnd = CreateWindowEx( 0, lpClassName, lpWndName,
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT, 
		CW_USEDEFAULT, NULL, NULL, g_hInstance,
		NULL );
	return hWnd;
}
//��ʾ����
void Display( HWND hWnd )
{
	ShowWindow( hWnd, SW_SHOW );
	UpdateWindow( hWnd );
}
//��Ϣѭ��
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




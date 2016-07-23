#include "stdafx.h"
#include "stdio.h"
HINSTANCE g_hInstance = 0;//���յ�ǰ����ʵ�����
//���ڴ�����
LRESULT CALLBACK WndProc( HWND hWnd, UINT msg, 
												 WPARAM wParam, LPARAM lParam )
{
	switch( msg )
	{
		case WM_DESTROY:
			PostQuitMessage( 0 );//�ܹ�ʹGetMessage����0����
			break;
	}
	return DefWindowProc( hWnd, msg, wParam, lParam );
}
//ע�ᴰ����
BOOL Register( LPSTR lpClassName, WNDPROC wndProc )
{
	WNDCLASSEX wce = { 0 };
	wce.cbSize = sizeof( wce );
	wce.cbClsExtra = 200;
	wce.cbWndExtra = 200;
	wce.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wce.hCursor = NULL;
	wce.hIcon = NULL;
	wce.hIconSm = NULL;
	wce.hInstance = g_hInstance;
	wce.lpfnWndProc = wndProc;/************************/
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
//�����Ӵ���
HWND CreateChild( LPSTR lpClassName, LPSTR lpWndName,
								 HWND hParent )
{
	HWND hChild = CreateWindowEx( 0, lpClassName, lpWndName,
		WS_CHILD|WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		100, 100, 200, 200, hParent, NULL,
		g_hInstance, NULL );
	return hChild;
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
//д������
void SetExtra( HWND hWnd )
{
	char *pszText = "hello data";
	SetClassLong( hWnd, 196, (LONG)pszText );
	SetWindowLong( hWnd, 0, 100 );
}
//��ȡ����
void GetExtra( HWND hWnd )
{
	long nClass = GetClassLong( hWnd, 196 );
	char *pszText = (char*)nClass;
	long nWnd = GetWindowLong( hWnd, 0 );
	char szText[256] = { 0 };
	sprintf( szText, "������:%s,����:%d", pszText, nWnd );
	MessageBox( NULL, szText, "Infor", MB_OK );
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
	Register( "Child", DefWindowProc );
	HWND hChild1 = CreateChild( "Child", "c1", hWnd );
	HWND hChild2 = CreateChild( "Child", "c2", hWnd );
	MoveWindow( hChild1, 300, 100, 200, 200, TRUE );
	MoveWindow( hChild2, 500, 100, 200, 200, TRUE );
	
	SetExtra( hChild1 );
	GetExtra( hChild2 );
	Message( );
	
	return 0;
}




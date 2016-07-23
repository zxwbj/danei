#include "stdafx.h"
HINSTANCE g_hInstance = 0;//���յ�ǰ����ʵ�����
void OnPaint( HWND hWnd )
{
	PAINTSTRUCT ps = { 0 };
	HDC hdc = BeginPaint( hWnd, &ps );
	SetTextColor( hdc, RGB(255,0,0) );
	SetBkColor( hdc, RGB(0,255,0) );//ֻ������OPAQUEģʽ
	SetBkMode( hdc, TRANSPARENT );

	HFONT hFont = CreateFont( 30, 0, 45, 0, 900, 1,
					1, 1, GB2312_CHARSET, 0, 0, 0, 0,
					"����" );
	HGDIOBJ nOldFont = SelectObject( hdc, hFont );

	char szText[] = "hello&txt";
	TextOut( hdc, 100, 100, szText, strlen(szText) );

	RECT rc = { 0 };
	rc.left = 100;
	rc.top = 150;
	rc.right = 200;
	rc.bottom = 200;
//	Rectangle( hdc, 100, 150, 200, 200 );
	DrawText( hdc, szText, strlen(szText), &rc, 
			DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_NOCLIP|
			DT_NOPREFIX );
	/*
	DT_VCENTER / DT_BOTTOM - ֻ������DT_SINGLELINE
	DT_WORDBREAK - �����У��ַ���ֻ�ܿ����˻���
	*/
	char szExtText[] = "A�й�����";
	int nDis[] = { 10,0,20,0,30,0,40,0 };
	ExtTextOut( hdc, 100, 300, 0, NULL, szExtText,
					strlen(szExtText), nDis );

	SelectObject( hdc, nOldFont );
	DeleteObject( hFont );
	EndPaint( hWnd, &ps );
}
//���ڴ�����
LRESULT CALLBACK WndProc( HWND hWnd, UINT msg, 
						 WPARAM wParam, LPARAM lParam )
{
	switch( msg )
	{
	case WM_PAINT:
		OnPaint( hWnd );
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
	wce.hbrBackground = (HBRUSH)(COLOR_WINDOW+3);
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
	char szTitle[256] = { 0 };
	HWND hWnd = CreateMain( "Main", "window" );
	Display( hWnd );
	Message( );
	return 0;
}




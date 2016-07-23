#include "stdafx.h"
#include "resource.h"
HINSTANCE g_hInstance = 0;//接收当前程序实例句柄
int g_kind = 0;//标志量
void OnCommand( HWND hWnd, WPARAM wParam )
{
	g_kind = LOWORD(wParam);
	switch( LOWORD(wParam) )
	{
		case ID_PIT:
		case ID_LINE:
		case ID_REC:
		case ID_ELL:
		case ID_ARC:
		case ID_BMP:
			InvalidateRect( hWnd, NULL, TRUE );
			break;
	}
}
void DrawPit( HDC hdc )
{
//	SetPixel( hdc, 100, 100, RGB(255,0,0) );
	for( int i=0; i<256; i++ )
	{
		for( int j=0; j<256; j++ )
		{
			SetPixel( hdc, i, j, RGB(i,j,0) );
		}
	}
}
void DrawLine( HDC hdc )
{
	MoveToEx( hdc, 100, 100, NULL );
	LineTo( hdc, 300, 300 );
	LineTo( hdc, 0, 300 );
	LineTo( hdc, 100, 100 );
}
void DrawRec( HDC hdc )
{
	Rectangle( hdc, 100, -100, 300, -300 );
	RoundRect( hdc, 300, 100, 500, 300, 200, 200 );
}
void DrawEll( HDC hdc )
{
	Ellipse( hdc, 100, 100, 300, 300 );
	Ellipse( hdc, 300, 100, 600, 300 );
}
void DrawArc( HDC hdc )
{
	SetArcDirection( hdc, AD_CLOCKWISE );//顺时针取弧
	Arc( hdc, 100, 100, 300, 300, 100, 100, 300, 300 );
}
void DrawBmp( HDC hdc )
{
	//添加资源
	HBITMAP hBmp = LoadBitmap(	g_hInstance,
						MAKEINTRESOURCE(IDB_BITMAP1) );
	BITMAP bmpInfo = { 0 };
	GetObject( hBmp, sizeof(bmpInfo), &bmpInfo );
	//动态获取位图的宽和高
	HDC hMemdc = CreateCompatibleDC( hdc );
	//创建一个内存DC，同时在内存中构建了一个虚拟区域
	//创建一个内存DC，同时申请相应大小一块内存
	HGDIOBJ nOldBmp = SelectObject( hMemdc, hBmp );
	//图片送给内存DC后内存dc立即将图片在虚拟区域中绘制出来
	//将图片的数据扔到内存DC找到的那块内存中
	BitBlt( hdc, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, 
				hMemdc, 0, 0, SRCCOPY );
	//1:1成像
	//将内存中图片数据 一次性 拷贝到 显存中
	StretchBlt( hdc, 100, 100, 96, 96, 
				hMemdc, 0, 0, 
				bmpInfo.bmWidth, bmpInfo.bmHeight,
				SRCCOPY );
	//缩放成像
	SelectObject( hMemdc, nOldBmp );
	DeleteObject( hBmp );
	DeleteDC( hMemdc );
}
void OnPaint( HWND hWnd )
{
	PAINTSTRUCT ps = { 0 };
	HDC hdc = BeginPaint( hWnd, &ps );
	HPEN hPen = CreatePen( PS_DASH, 1, RGB(255,0,0) );
	HGDIOBJ nOldPen = SelectObject( hdc, hPen );
//	HBRUSH hBrush = CreateSolidBrush( RGB(0,255,0) );
//	HBRUSH hBrush = CreateHatchBrush( 
//							HS_BDIAGONAL, RGB(0,255,0) );
//	HGDIOBJ hBrush = GetStockObject( NULL_BRUSH );
	HBITMAP hBmp = LoadBitmap( g_hInstance,
						MAKEINTRESOURCE(IDB_BITMAP1) );
	HBRUSH hBrush = CreatePatternBrush( hBmp );
	HGDIOBJ nOldBrush = SelectObject( hdc, hBrush );

	int nOldMode = SetMapMode( hdc, MM_ANISOTROPIC );
	SetWindowExtEx( hdc, -1, -1, NULL );
	SetViewportExtEx( hdc, -2, -3, NULL );
	switch( g_kind )
	{
		case ID_BMP:
			DrawBmp( hdc );//绘制位图
			break;
		case ID_ARC:
			DrawArc( hdc );//绘制弧线
			break;
		case ID_ELL:
			DrawEll( hdc );//绘制圆形
			break;
		case ID_REC:
			DrawRec( hdc );//绘制矩形
			break;
		case ID_LINE:
			DrawLine( hdc );//绘制直线
			break;
		case ID_PIT:
			DrawPit( hdc );//绘制点
			break;
	}
	SetMapMode( hdc, nOldMode );
	SelectObject( hdc, nOldBrush );
	DeleteObject( hBrush );
	SelectObject( hdc, nOldPen );
	DeleteObject( hPen );
	EndPaint( hWnd, &ps );
}
//窗口处理函数
LRESULT CALLBACK WndProc( HWND hWnd, UINT msg, 
												 WPARAM wParam, LPARAM lParam )
{
	switch( msg )
	{
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
	wce.hbrBackground = CreateSolidBrush( RGB(0,0,255) );
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
	HWND hWnd = CreateMain( "Main", "window" );
	Display( hWnd );
	Message( );
	return 0;
}




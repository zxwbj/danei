#include "stdafx.h"
//窗口处理函数(处理消息)
LRESULT CALLBACK WndProc( HWND hWnd, UINT nMsg,
													WPARAM wParam, LPARAM lParam )
{
	return DefWindowProc( hWnd, nMsg, wParam, lParam );
}
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	//注册窗口类（向操作系统中写一些数据）
	WNDCLASS wc = { 0 };
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.hCursor = NULL;
	wc.hIcon = NULL;
	wc.hInstance = hInstance;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.lpszClassName = "Main";
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass( &wc );//将以上所有赋值全部写入操作系统
	//创建窗口（申请一块内存，向内存中扔关于窗口数据）
	HWND hWnd = CreateWindow( "Main", "window", 
								WS_OVERLAPPEDWINDOW,
								100, 100, 500, 500, NULL, NULL, 
								hInstance, NULL );
	//显示窗口
	ShowWindow( hWnd, SW_SHOW );
//	UpdateWindow( hWnd );
	//消息循环
	MSG uMsg = { 0 };
	while( GetMessage(&uMsg, NULL, 0, 0) )
	{
		TranslateMessage( &uMsg );
		DispatchMessage( &uMsg );//派发给自己定义的函数
	}
	return 0;
}




#include "stdafx.h"
//���ڴ�����(������Ϣ)
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
	//ע�ᴰ���ࣨ�����ϵͳ��дһЩ���ݣ�
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
	RegisterClass( &wc );//���������и�ֵȫ��д�����ϵͳ
	//�������ڣ�����һ���ڴ棬���ڴ����ӹ��ڴ������ݣ�
	HWND hWnd = CreateWindow( "Main", "window", 
								WS_OVERLAPPEDWINDOW,
								100, 100, 500, 500, NULL, NULL, 
								hInstance, NULL );
	//��ʾ����
	ShowWindow( hWnd, SW_SHOW );
//	UpdateWindow( hWnd );
	//��Ϣѭ��
	MSG uMsg = { 0 };
	while( GetMessage(&uMsg, NULL, 0, 0) )
	{
		TranslateMessage( &uMsg );
		DispatchMessage( &uMsg );//�ɷ����Լ�����ĺ���
	}
	return 0;
}




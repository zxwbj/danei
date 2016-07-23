#include "windows.h"
int WinMain( HINSTANCE hIns, HINSTANCE hPrev,
             LPSTR lpCmdLine, int nCmdShow )
{
  MessageBox( NULL, "hello world", "Infor",
	MB_ABORTRETRYIGNORE|MB_ICONQUESTION );
  return 0;
}
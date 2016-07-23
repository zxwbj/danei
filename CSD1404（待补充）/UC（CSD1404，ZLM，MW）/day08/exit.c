#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char* g_p = NULL;
void doexit1 (void) {
	printf ("我即将死掉！啊~~~~~\n");
	free (g_p);
}
void doexit2 (int status, void* arg) {
	printf ("退出状态：%d\n", status);
	printf ("退出参数：%s\n", (char*)arg);
}
void foo (void) {
	FILE* fp = fopen ("none", "r");
	if (! fp) {
//	free (g_p);
//	exit (1122);
		exit (EXIT_FAILURE);
	}
	// ...
	fclose (fp);
//exit (EXIT_SUCCESS);
//_exit (EXIT_SUCCESS);
	_Exit (EXIT_SUCCESS);
}
int main (void) {
	atexit (doexit1);
	on_exit (doexit2, "我的临终遗言...");
	g_p = malloc (1024);
	printf ("马上调用exit()函数了！\n");
	foo ();
//free (g_p);
//exit (1234);
	return 5678;
}

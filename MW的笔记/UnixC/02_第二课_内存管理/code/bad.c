#include <stdio.h>
#include <limits.h>

// 获取文件大小
// 成功返回文件大小，失败返回-1
long fsize (const char* path) {
	FILE* fp = fopen (path, "r");
	if (! fp)
		return -1;

	fseek (fp, 0, SEEK_END);
	long size = ftell (fp);

	fclose (fp);

	return size;
}

int main (void) {
	printf ("文件路径：");
	char path[PATH_MAX+1];
	scanf ("%s", path);

	long size = fsize (path);
	if (size < 0) {
		printf ("获取文件大小失败！\n");
		return -1;
	}

	printf ("文件大小：%ld字节\n", size);

	return 0;
}

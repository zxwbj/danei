#include <stdio.h>

// 求字符串长度
// 成功返回字符串长度，失败返回(size_t)-1
size_t slen (const char* s) {
	if (! s)
		return -1;

	size_t len;
	for (len = 0; s[len]; ++len);

	return len;
}

// 字符串拷贝
// 成功返回目标字符串，失败返回NULL
char* scpy (char* dst, size_t size, const char* src) {
	if (! dst || ! size || ! src)
		return NULL;

	if (dst != src) {
		size_t i, count = min (size - 1, slen (src));

		if (dst > src)
			for (i = 0; i < count; ++i)
				dst[count - 1 - i] = src[count - 1 - i];
		else
			for (i = 0; i < count; ++i)
				dst[i] = src[i];

		dst[count] = '\0';
	}

	return dst;
}

// 求整数最小值
// 成功返回0，失败返回-1
int intmin (int a, int b, int* min) {
	if (a == b)
		return -1;

	*min = a < b ? a : b;

	return 0;
}

// 求整数平均值
// 成功返回参数整数的平均值，不会失败
int intave (int a, int b) {
	return (a & b) + ((a ^ b) >> 1);
}
/*
  109 = 01101101 = 00100101 + 01001000
   55 = 00110111 = 00100101 + 00010010
+)------------------------------------
             a+b = (a&b)*2  + (a^b)
         (a+b)/2 = (a&b) + (a^b)>>1
                 = 37    + 01011010>>1
                 = 37    + 00101101
                 = 37    + 45
                 = 82
*/
int main (void) {
	size_t len = slen ("Hello World !");
//	size_t len = slen (NULL);
	if (len == -1)
		printf ("求字符串长度失败！\n");
	else
		printf ("字符串长度：%u\n", len);

	char dst[5];
	if (! scpy (dst, sizeof (dst) / sizeof (dst[0]), "0123456789"))
//	if (! scpy (NULL, 0, "0123456789"))
		printf ("字符串拷贝失败！\n");
	else
		printf ("字符串副本：%s\n", dst);

	int min;
	if (intmin (-1, 0, &min) == -1)
//	if (intmin (-1, -1, &min) == -1)
		printf ("求整数最小值失败！\n");
	else
		printf ("整数最小值：%d\n", min);

	printf ("整数平均值：%d\n", intave (1234, 5678));

	return 0;
}

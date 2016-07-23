/*
 * 编写程序，根据输入的n(>=2)生成
 * nxn的zigzag矩阵。
 * 例如：n = 5
 *  0  1  5  6 14
 *  2  4  7 13 15
 *  3  8 12 16 21
 *  9 11 17 20 22
 * 10 18 19 23 24
 */
#include <stdio.h>
int main (void) {
	printf ("n = ");
	int n;
	scanf ("%d", &n);
	if (n < 2) {
		printf ("n不能小于2！\n");
		return -1;
	}
	int m[n][n], i = 0, j = 0, k = 0, d;
	m[i][j] = k++;
	for (d = 2; d <= n; ++d)
		if (d % 2) {
			for (++i; j < d; --i, ++j)
				m[i][j] = k++;
			++i, --j;
		}
		else {
			for (++j; i < d; ++i, --j)
				m[i][j] = k++;
			--i, ++j;
		}
	for (d = n - 1; d >= 2; --d)
		if (d % 2) {
			for (++j; j < n; --i, ++j)
				m[i][j] = k++;
			++i, --j;
		}
		else {
			for (++i; i < n; ++i, --j)
				m[i][j] = k++;
			--i, ++j;
		}
	m[i][++j] = k++;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j)
			printf ("%3d ", m[i][j]);
		printf ("\n");
	}
	return 0;
}
/*
nxn蛇形矩阵：
 0  1  8  9 24
 3  2  7 10 23
 4  5  6 11 22
15 14 13 12 21
16 17 18 19 20
nxn螺旋矩阵：
 0  1  2  3  4
15 16 17 18  5
14 23 24 19  6
13 22 21 20  7
12 11 10  9  8
*/

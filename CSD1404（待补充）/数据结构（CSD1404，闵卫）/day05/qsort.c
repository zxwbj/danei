#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmpint (const void* a, const void* b) {
	return *(const int*)a - *(const int*)b;
}
int cmpstr (const void* a, const void* b) {
	return strcmp (*(const char* const*)a,
		*(const char* const*)b);
}
typedef struct Student {
	char name[256];
	int age;
}	STUDENT;
int cmpstu (const void* a, const void* b) {
	STUDENT const* pa = (STUDENT const*)a;
	STUDENT const* pb = (STUDENT const*)b;
	int res = strcmp (pa->name, pb->name);
	if (! res)
		return pb->age - pa->age;
	return res;
}
void _myqsort (void* base, size_t left,
	size_t right, size_t size,
	int (*compar) (const void*, const void*)) {
	size_t p = (left + right) / 2;
	void* pivot = malloc (size);
	memcpy (pivot, base+p*size, size);
	size_t i = left, j = right;
	while (i < j) {
		for (; ! (i>=p ||
			compar (pivot, base+i*size)<0); ++i);
		if (i < p) {
			memcpy (base+p*size, base+i*size, size);
			p = i;
		}
		for (; ! (j<=p ||
			compar (base+j*size, pivot)<0); --j);
		if (j > p) {
			memcpy (base+p*size, base+j*size, size);
			p = j;
		}
	}
	memcpy (base+p*size, pivot, size);
	free (pivot);
	if (p - left > 1)
		_myqsort (base, left, p-1, size, compar);
	if (right - p > 1)
		_myqsort (base, p+1,right, size, compar);
}
void myqsort (void* base, size_t nmemb,
	size_t size,
	int (*compar) (const void*,	const void*)) {
	_myqsort (base, 0, nmemb - 1, size, compar);
}
int main (void) {
	int na[] = {34, 56, 17, 88, 41};
	size_t size = sizeof (na[0]);
	size_t nmemb = sizeof (na) / size;
	myqsort (na, nmemb, size, cmpint);
	size_t i;
	for (i = 0; i < nmemb; ++i)
		printf ("%d ", na[i]);
	printf ("\n");
	const char* sa[] = {"beijing", "shanghai",
		"chongqing", "tianjin", "xian"};
	size = sizeof (sa[0]);
	nmemb = sizeof (sa) / size;
	myqsort (sa, nmemb, size, cmpstr);
	for (i = 0; i < nmemb; ++i)
		printf ("%s ", sa[i]);
	printf ("\n");
	STUDENT ta[] = {
		{"zhangming", 22},
		{"wanghong", 25},
		{"liming", 23},
		{"wanghong", 30},
		{"liming", 40}};
	size = sizeof (ta[0]);
	nmemb = sizeof (ta) / size;
	myqsort (ta, nmemb, size, cmpstu);
	for (i = 0; i < nmemb; ++i)
		printf ("%s, %d\n", ta[i].name,ta[i].age);
	return 0;
}

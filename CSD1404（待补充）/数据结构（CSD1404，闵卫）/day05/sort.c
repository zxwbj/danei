#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 冒泡排序 */
void bubble_sort (int data[], size_t size) {
	size_t i;
	for (i = 0; i < size - 1; ++i) {
		int ordered = 1;
		size_t j;
		for (j = 0; j < size - 1 - i; ++j)
			if (data[j+1] < data[j]) {
				int swap = data[j];
				data[j] = data[j+1];
				data[j+1] = swap;
				ordered = 0;
			}
		if (ordered)
			break;
	}
}
/* 插入排序 */
void insert_sort (int data[], size_t size) {
	size_t i;
	for (i = 1; i < size; ++i) {
		int inserted = data[i];
		size_t j;
		for (j=i; j>0 && inserted<data[j-1]; --j)
			data[j] = data[j-1];
		if (j != i)
			data[j] = inserted;
	}
}
/* 选择排序 */
void select_sort (int data[], size_t size) {
	size_t i;
	for (i = 0; i < size - 1; ++i) {
		size_t j, min = i;
		for (j = i + 1; j < size; ++j)
			if (data[j] < data[min])
				min = j;
		if (min != i) {
			int swap = data[i];
			data[i] = data[min];
			data[min] = swap;
		}
	}
}
/* 快速排序 */
void quick_sort (int data[], size_t left,
	size_t right) {
	size_t p = (left + right) / 2;
	int pivot = data[p];
	size_t i = left, j = right;
	while (i < j) {
		for (; ! (i>=p || pivot<data[i]); ++i);
		if (i < p) {
			data[p] = data[i];
			p = i;
		}
		for (; ! (j<=p || data[j]<pivot); --j);
		if (j > p) {
			data[p] = data[j];
			p = j;
		}
	}
	data[p] = pivot;
	if (p - left > 1)
		quick_sort (data, left, p - 1);
	if (right - p > 1)
		quick_sort (data, p + 1, right);
}
/* 外部合并 */
void outer_merge (int data1[], size_t size1,
	int data2[], size_t size2, int data3[]) {
	size_t i = 0, j = 0, k = 0;
	for (;;)
		if (i < size1 && j < size2)
			if (data2[j] < data1[i])
				data3[k++] = data2[j++];
			else
				data3[k++] = data1[i++];
		else
		if (i < size1)
			data3[k++] = data1[i++];
		else
		if (j < size2)
			data3[k++] = data2[j++];
		else
			break;
}
/* 内部合并 */
void inner_merge (int data[], size_t left,
	size_t mid, size_t right) {
	size_t size = (right-left+1)*sizeof(int);
	int* merge = malloc (size);
	outer_merge (data+left, mid-left+1,
		data+mid+1, right-mid, merge);
	memcpy (data+left, merge, size);
	free (merge);
}
/* 归并排序 */
void merge_sort (int data[], size_t left,
	size_t right) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort (data, left, mid);
		merge_sort (data, mid+1, right);
		inner_merge (data, left, mid, right);
	}
}
/* 测试用例 */
int main (void) {
	srand (time (NULL));
	int data[10];
	size_t i, size=sizeof(data)/sizeof(data[0]);
	for (i = 0; i < size; ++i)
		printf ("%2d ", data[i] = rand () % 100);
	printf ("\n");
	/*
	bubble_sort (data, size);
	insert_sort (data, size);
	select_sort (data, size);
	quick_sort (data, 0, size - 1);
	*/
	merge_sort (data, 0, size - 1);
	for (i = 0; i < size; ++i)
		printf ("%2d ", data[i]);
	printf ("\n");
	return 0;
}

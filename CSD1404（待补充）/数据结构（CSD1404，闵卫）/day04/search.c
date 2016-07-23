#include <stdio.h>
int line_find (int data[], int size, int key){
	int i;
	for (i = 0; i < size; ++i)
		if (data[i] == key)
			return i;
	return -1;
}
int half_find (int data[], int left,
	int right, int key) {
	if (left <= right) {
		int mid = (left + right) / 2;
		if (key < data[mid])
			return half_find (data, left, mid - 1,
				key);
		if (data[mid] < key)
			return half_find (data, mid + 1, right,
				key);
		return mid;
	}
	return -1;
}
int biny_find (int data[], int size, int key){
	int left = 0, right = size - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (key < data[mid])
			right = mid - 1;
		else
		if (data[mid] < key)
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}
int main (void) {
	int data[] = {12, 34, 23, 47, 19};
	int size = sizeof(data)/sizeof(data[0]);
	int res = line_find (data, size, 45);
	if (res == -1)
		printf ("没找到！\n");
	else
		printf ("找到了：data[%d] = %d\n", res,
			data[res]);
	int sort[] = {12, 19, 23, 34, 47};
	size = sizeof(sort)/sizeof(sort[0]);
	/*
	if ((res = half_find (sort, 0, size - 1,
		35)) == -1)
	*/
	if ((res = biny_find (sort, size, 35))==-1)
		printf ("没找到！\n");
	else
		printf ("找到了：sort[%d] = %d\n", res,
			sort[res]);
	return 0;
}

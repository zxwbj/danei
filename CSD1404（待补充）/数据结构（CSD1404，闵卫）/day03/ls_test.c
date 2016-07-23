/* 双向线性链表 */
#include <stdio.h>
#include "ls.h"
/* 测试用例 */
void print (LIST* list) {
	/*
	size_t pos, size = list_size (list);
	for (pos = 0; pos < size; ++pos)
		printf ("%d ", *list_at (list, pos));
	printf ("\n");
	*/
	/*
	for (list_begin (list); ! list_end (list);
		list_next (list))
		printf ("%d ", *list_current (list));
	printf ("\n");
	*/
	for (list_rbegin (list); ! list_rend (list);
		list_rnext (list))
		printf ("%d ", *list_rcurrent (list));
	printf ("\n");
}
void square (LIST* list) {
	for (list_begin (list); ! list_end (list);
		list_next (list))
		*list_current (list) *=
			*list_current (list);
}
void test1 (void) {
	LIST list;
	list_init (&list);
	list_append (&list, 10);
	list_append (&list, 30);
	list_append (&list, 50);
	print (&list); /* 10 30 50 */
	list_insert (&list, 1, 20);
	list_insert (&list, 3, 40);
	print (&list); /* 10 20 30 40 50 */
	list_erase (&list, 2);
	list_erase (&list, 3);
	print (&list); /* 10 20 40 */
	list_append (&list, 20);
	list_insert (&list, 0, 20);
	print (&list); /* 20 10 20 40 20 */
	list_remove (&list, 20);
	print (&list); /* 10 40 */
	square (&list);
	print (&list);
	list_deinit (&list);
}
int main (void) {
	test1 ();
	return 0;
}

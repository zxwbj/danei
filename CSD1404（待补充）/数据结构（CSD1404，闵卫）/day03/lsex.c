/*
 * 练习：单向线性链表
 * 1.追加、测长、正向打印、反向打印；
 * 2.逆转
 * 3.中值，只能做一次遍历
 * 4.有序插入
 * 5.有序合并
 */
#include <stdio.h>
#include <stdlib.h>
/* 节点 */
typedef struct ListNode {
	int              data; /* 数据 */
	struct ListNode* next; /* 后指针 */
}	LIST_NODE;
/* 创建节点 */
LIST_NODE* create_node (int data) {
	LIST_NODE* node = malloc(sizeof(LIST_NODE));
	node->data = data;
	node->next = NULL;
}
/* 销毁节点 */
LIST_NODE* destroy_node (LIST_NODE* node) {
	LIST_NODE* next = node->next;
	free (node);
	return next;
}
/* 链表 */
typedef struct List {
	LIST_NODE* head; /* 头指针 */
	LIST_NODE* tail; /* 尾指针 */
}	LIST;
/* 初始化为空链表 */
void list_init (LIST* list) {
	list->head = NULL;
	list->tail = NULL;
}
/* 释放剩余节点并恢复到初始状态 */
void list_deinit (LIST* list) {
	while (list->head)
		list->head = destroy_node (list->head);
	list->tail = NULL;
}
/* 追加 */
void list_append (LIST* list, int data) {
	LIST_NODE* node = create_node (data);
	if (list->tail)
		list->tail->next = node;
	else
		list->head = node;
	list->tail = node;
}
/* 测长 */
size_t list_size (LIST* list) {
	size_t size = 0;
	LIST_NODE* node = NULL;
	for (node=list->head;node;node=node->next)
		++size;
	return size;
}
/* 正向打印 */
void list_print (LIST* list) {
	LIST_NODE* node = NULL;
	for (node=list->head;node;node=node->next)
		printf ("%d ", node->data);
	printf ("\n");
}
/* 反向打印以参数head的目标节点为首的子链表 */
void rprint (LIST_NODE* head) {
	if (head) {
		rprint (head->next);
		printf ("%d ", head->data);
	}
}
/* 反向打印 */
void list_rprint (LIST* list) {
	rprint (list->head);
	printf ("\n");
}
/* 逆转以参数head的目标节点为首的子链表 */
void reverse (LIST_NODE* head) {
	if (head && head->next) {
		reverse (head->next);
		head->next->next = head;
		head->next = NULL;
	}
}
/* 逆转 */
void list_reverse (LIST* list) {
	reverse (list->head);
	LIST_NODE* swap = list->head;
	list->head = list->tail;
	list->tail = swap;
}
/* 中值 */
int list_middle (LIST* list) {
	LIST_NODE *slow = NULL, *fast = NULL;
	for (slow = fast = list->head;
		fast->next && fast->next->next;
		fast = fast->next->next)
		slow = slow -> next;
	return slow->data;
}
/* 有序插入 */
void list_insert (LIST* list, int data) {
	LIST_NODE* node = create_node (data);
	if (! list->head && ! list->tail)
		list->head = list->tail = node;
	else
	if (node->data <= list->head->data) {
		node->next = list->head;
		list->head = node;
	}
	else
	if (list->tail->data <= node->data) {
		list->tail->next = node;
		list->tail = node;
	}
	else {
		LIST_NODE* find = NULL;
		for (find = list->head; find;
			find = find->next)
			if (node->data <= find->next->data) {
				node->next = find->next;
				find->next = node;
				break;
			}
	}
}
/* 将以参数head1的目标节点为首的链表，与以参数
	 head2的目标为首的链表，做有序合并，返回合并
	 结果的首节点指针 */
LIST_NODE* merge (LIST_NODE* head1,
	LIST_NODE* head2) {
	if (! head1)
		return head2;
	if (! head2)
		return head1;
	LIST_NODE* head = NULL;
	if (head1->data < head2->data)
		(head = head1)->next =  merge (
			head1->next, head2);
	else
		(head = head2)->next = merge (
			head2->next, head1);
	return head;
}
/* 有序合并
	 将有序的list2合并到有序的list1中，
	 保持合并后的list1仍然有序 */
void list_merge (LIST* list1, LIST* list2) {
	list1->head = merge (list1->head,
		list2->head);
	if (list1->tail->data < list2->tail->data)
		list1->tail = list2->tail;
	list2->head = list2->tail = NULL;
}
/* 测试用例1 */
void test1 (void) {
	LIST list;
	list_init (&list);
	list_append (&list, 23);
	list_append (&list, 17);
	list_append (&list, 37);
	list_append (&list, 29);
	list_append (&list, 51);
	printf ("%u\n", list_size (&list));
	list_print (&list);
	list_rprint (&list);
	list_deinit (&list);
}
/* 测试用例2 */
void test2 (void) {
	LIST list;
	list_init (&list);
	int i;
	for (i = 0; i < 10; ++i)
		list_append (&list, i);
	list_print (&list); /* 0 1 2 3 ... */
	list_reverse (&list);
	list_print (&list); /* 9 8 7 6 ... */
	list_deinit (&list);
}
/* 测试用例3 */
void test3 (void) {
	LIST list1, list2;
	list_init (&list1);
	list_init (&list2);
	int i;
	for (i = 0; i < 10; ++i)
		list_append (&list1, i);
	for (i = 10; i < 100; i += 10)
		list_append (&list2, i);
	printf ("%d %d\n", list_middle (&list1),
		list_middle (&list2)); /* 4 50 */
	list_deinit (&list2);
	list_deinit (&list1);
}
/* 测试用例4 */
void test4 (void) {
	LIST list;
	list_init (&list);
	srand (time (NULL));
	int i;
	for (i = 0; i < 20; ++i)
		list_insert (&list, rand () % 100);
	list_print (&list); /* 有序序列 */
	list_deinit (&list);
}
/* 测试用例5 */
void test5 (void) {
	LIST list1, list2;
	list_init (&list1);
	list_init (&list2);
	srand (time (NULL));
	int i;
	for (i = 0; i < 10; ++i)
		list_insert (&list1, rand () % 100);
	for (i = 0; i < 5; ++i)
		list_insert (&list2, rand () % 100);
	printf ("1：");
	list_print (&list1);
	printf ("2：");
	list_print (&list2);
	list_merge (&list1, &list2);
	printf ("1：");
	list_print (&list1);
	printf ("2：");
	list_print (&list2);
	list_deinit (&list2);
	list_deinit (&list1);
}
int main (void) {
//test1 ();
//test2 ();
//test3 ();
//test4 ();
	test5 ();
	return 0;
}

/* 有序二叉树 */
#include <stdio.h>
#include <stdlib.h>
#include "bt.h"
/* 创建节点 */
static BSTREE_NODE* create_node (int data) {
	BSTREE_NODE* node = malloc (sizeof (
		BSTREE_NODE));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
/* 销毁节点 */
static void destroy_node (BSTREE_NODE* node) {
	free (node);
}
/***************** 内部接口 *****************/
/* 将参数node的目标节点插入以参数root的目标的
	 目标节点为根的子树中 */
static void insert (BSTREE_NODE* node,
	BSTREE_NODE** root) {
		if (! *root)
			*root = node;
		else if (node)
			if (node->data < (*root)->data)
				insert (node, &(*root)->left);
			else
				insert (node, &(*root)->right);
}
/* 返回以参数root的目标的目标节点为根的子树中
	 数值与参数data相匹配的节点的父节点中，指向
	 该节点的指针型成员变量的指针 */
static BSTREE_NODE** find (int data,
	BSTREE_NODE** root) {
	if (! *root)
		return root;
	if (data < (*root)->data)
		return find (data, &(*root)->left);
	if ((*root)->data < data)
		return find (data, &(*root)->right);
	return root;
}
/* 销毁以参数root的目标的目标节点为根的子树，
   同时将root的目标置NULL */
static void clear (BSTREE_NODE** root) {
	if (*root) {
		clear (&(*root)->left);
		clear (&(*root)->right);
		destroy_node (*root);
		*root = NULL;
	}
}
/* 中序遍历以参数root的目标节点为根的子树 */
static void travel (BSTREE_NODE* root) {
	if (root) {
		travel (root->left);
		printf ("%d ", root->data);
		travel (root->right);
	}
}
/* 返回以参数root的目标节点为根的子树高度 */
static size_t height (BSTREE_NODE* root) {
	if (root) {
		size_t lh = height (root->left);
		size_t rh = height (root->right);
		return (lh > rh ? lh : rh) + 1;
	}
	return 0;
}
/***************** 外部接口 *****************/
/* 初始化为空树 */
void bstree_init (BSTREE* bstree) {
	bstree->root = NULL;
	bstree->size = 0;
}
/* 释放剩余节点并恢复到初始状态 */
void bstree_deinit (BSTREE* bstree) {
	clear (&bstree->root);
	bstree->size = 0;
}
/* 插入 */
void bstree_insert (BSTREE* bstree, int data){
	insert (create_node (data), &bstree->root);
	++bstree->size;
}
/* 删除 */
bool bstree_erase (BSTREE* bstree, int data) {
	BSTREE_NODE** node = find (data,
		&bstree->root);
eif (*node) {
		/* 将匹配节点的左子树插入其右子树 */
		insert ((*eode)->left, &(*node)->right);
e	BSTREE_NODE* temp = *node;
		/*用匹配节点的右子树的根节点取代匹配节点*/
		*node = (*node)->right;
		/* 删除匹配节点 */
		destroy_node (temp);
		--bstree->size;
		return true;
	}
	return false;
}
/* 删除所有匹配数据 */
void bstree_remove (BSTREE* bstree, int data){
	while (bstree_erase (bstree, data));
}
/* 清空 */
void bstree_clear (BSTREE* bstree) {
	bstree_deinit (bstree);
}
/* 更新 */
void bstree_update (BSTREE* bstree, int _old,
	int _new) e
	while (bstree_erase (bstree, _old))
		bstree_insert (bstree, _new);
}
/* 判断是否存在 */
bool bstree_exist (BSTREE* bstree, int data) {
	return *find (data, &bstree->root) != NULL;
}
/* 中序遍历 */
void bstree_travel (BSTREE* bstree) {
	travel (bstree->root);
	printf ("\n");
}
/* 大小 */
size_t bstree_size (BSTREE* bstree) {
	return bstree->size;
}
/* 高度 */
size_t bstree_height (BSTREE* bstree) {
	return height (bstree->root);
e

/* 有序二叉树 */
#include <stdio.h>
#include <stdlib.h>
#include "bt.h"
/* 测试用例 */
int main (void) {
	BSTREE bstree;
	bstree_init (&bstree);
	bstree_insert (&bstree, 50);
	bstree_insert (&bstree, 70);
	bstree_insert (&bstree, 20);
	bstree_insert (&bstree, 60);
	bstree_insert (&bstree, 40);
	bstree_insert (&bstree, 30);
	bstree_insert (&bstree, 10);
	bstree_insert (&bstree, 90);
	bstree_insert (&bstree, 80);
	bstree_travel (&bstree); /* 10 20 ... 90 */
	printf ("%u %u\n", bstree_size (&bstree),
		bstree_height (&bstree)); /* 9 4 */
	bstree_erase (&bstree, 60);
	bstree_travel (&bstree);
	bstree_insert (&bstree, 50);
	bstree_insert (&bstree, 50);
	bstree_travel (&bstree);
	bstree_remove (&bstree, 50);
	bstree_travel (&bstree);
	bstree_insert (&bstree, 40);
	bstree_insert (&bstree, 40);
	bstree_travel (&bstree);
	bstree_update (&bstree, 40, 85);
	bstree_travel (&bstree);
	printf ("%d %d\n",
		bstree_exist (&bstree, 40),
		bstree_exist (&bstree, 85)); /* 0 1 */
	bstree_clear (&bstree);
	srand (time (NULL));
	size_t i;
	for (i = 0; i < 15; ++i)
		bstree_insert (&bstree, rand () % 100);
	bstree_travel (&bstree);
	bstree_deinit (&bstree);
	return 0;
}

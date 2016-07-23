/*
	 二级指针演示
	 */
#include <stdio.h>
int main() {
		int num = 0;
		int *p_num = &num;
		int **pp_num = &p_num;  //二级指针声明
		printf("%d\n", **pp_num);  //普通存储区中的数据
		**pp_num = 10;  //普通存储区本身
    printf("%p\n", *pp_num);  //捆绑一级指针存储区里的地址数据
		*pp_num = NULL;  //捆绑的一级指针存储区
		printf("%p\n", pp_num);  //二级指针存储区中的地址数据
		pp_num = NULL;   //二级指针本身的存储区
		return 0;
}





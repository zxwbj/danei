#include <stdio.h>
#pragma pack(1)//2
int main(){
  struct s {//结构的类型就是 struct s
	  char c1;
	  int i;
		char c2;
	};
	printf("size=%d\n",sizeof(struct s));
  return 0;
}


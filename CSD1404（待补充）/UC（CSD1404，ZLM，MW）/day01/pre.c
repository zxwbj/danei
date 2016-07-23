#include <stdio.h>
#define VERSION 3
#if(VERSION<3)
  #error "版本低"
#elif(VERSION>3)
  #warning "版本高"
#endif
#pragma GCC dependency "hello.c"
#pragma GCC poison goto
int main(){
	//goto ok;
  printf("hello c\n");
	ok:printf("over\n");
	return 0;
}



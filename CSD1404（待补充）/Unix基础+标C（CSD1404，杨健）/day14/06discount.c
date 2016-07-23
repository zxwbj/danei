/*
	 折扣比例演示
	 */
#include <stdio.h>
int main() {
#if  defined(ELITE)
	  printf("120%%\n");
#elif !defined(FACTORY) && !defined(ELITE)
		printf("100%%\n");
#else
		printf("80%%\n");
#endif
		return 0;
}

#include <stdio.h>
#include "add.h"

int main(){
  int x = add(2,3);
	double y = add2(2.1,3.1);
	printf("%d,%lf\n",x,y);
	return 0;
}


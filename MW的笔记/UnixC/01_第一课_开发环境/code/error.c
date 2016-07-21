#include <stdio.h>

#if (VERSION < 3)
	#error "版本太低！"
#elif (VERSION > 3)
	#warning "版本太高！"
#endif

int main (void) {
	printf ("版本：%d\n", VERSION);
	return 0;
}

#include <stdlib.h>
#include "01create.h"
int lottery[7];
void create(void) {
		int num = 0;
		for (num = 0;num <= 6;num++) {
				lottery[num] = rand() % 36 + 1;
		}
}

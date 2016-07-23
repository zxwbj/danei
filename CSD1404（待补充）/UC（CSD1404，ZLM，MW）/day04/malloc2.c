#include <stdio.h>
#include <stdlib.h>

int main(){
  int* p1 = malloc(4);
	int* p2 = malloc(10*4096);
	int* p3 = malloc(10*4096);
	printf("p1=%p,p2=%p,p3=%p\n",p1,p2,p3);
	printf("pid=%d\n",getpid());
	sleep(15); printf("超过33页了\n");
	int* p4 = malloc(13*4096);
	sleep(15);printf("释放回33页\n");
	free(p4);
	sleep(15);printf("全部释放\n");
	free(p3); free(p2); free(p1);
	while(1);
}



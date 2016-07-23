#include <stdio.h>
void  foo(){ 
		printf("foo()\n");
}
int main(){
    foo();
		foo(1);
		foo(1,2);
		showNum(100);
		showNum(1001);
}
int  showNum(int x){
    printf("x=%d\n",x);
}


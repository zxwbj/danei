#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int max(int a,int b,int* pi){
  if(a == b) return -1;
	*pi = (a>b)?a:b;
	return 0;
}
int rand10(){
  srand(time(0));
	int x = rand()%10;
	if(!x) return -1;
	return x;
}
void printstring(const char* str){
  printf("%s\n",str);
}
char* iserror(char* str){
  //if(str == "error") // ==比较的是内存地址
	if(!strcmp(str,"error"))//strcmp比较值
		return NULL;
	return str;
}
int main(){
  int x = 0;
	int res = max(-1,-2,&x);
	if(res == -1) printf("max出错\n");
	else printf("max=%d\n",x);
	res = rand10();
	if(res == -1) printf("rand出错\n");
	else printf("rand=%d\n",res);
	//char* s1 = "error";
	char s1[6] = "error";
	char* s2 = iserror(s1);
	if(s2 == NULL) printf("iserror出错\n");
	else printf("%s\n",s2);
}


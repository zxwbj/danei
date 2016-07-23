#include <stdio.h>
#include <stdlib.h>

int main(){
  putenv("VAR=ABC");//不存在就新增
	printf("%s\n",getenv("VAR"));//ABC
  putenv("VAR=abc");//存在就覆盖
	printf("%s\n",getenv("VAR"));//abc
	setenv("VAR","123",0);//不覆盖
	printf("%s\n",getenv("VAR"));//abc
	setenv("VAR","456",1);//覆盖
	printf("%s\n",getenv("VAR"));//456
	unsetenv("VAR");
	printf("VAR=%s\n",getenv("VAR"));//NULL
}


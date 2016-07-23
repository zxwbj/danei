#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
  extern char** environ;//所有程序共享
	char** ps = environ;//ps是局部变量，没影响
	//ps是字符串数组,存了所有环境变量,NULL结束
  while(*ps/*!=NULL*/){
	  printf("%s\n",*ps);
		//*ps++;//r 先++后*,白取了一次*
		ps++;//r ps移动sizeof(char*),4字节
		//**ps++;//r 白取了两次*
		//(*ps)++;//w *ps移动一个字节
	}
	ps = environ;//又回到了开始
	char value[100] = {};//数组是常指针,strcpy()
	//练习：循环找到LANG，并把它的值放入value中
	//循环结束后打印value的值
  //strncmp()可以比较前n个字符
  while(*ps){
	  if(!strncmp(*ps,"LANG=",5)){//相等
	    //value = *ps+5;//字符串都以'\0'结尾	  
		  strcpy(value,*ps+5);
			break;
		}
		ps++;
	}
	printf("value=%s\n",value);
	printf("%s\n",getenv("LANG"));
	return 0;
}


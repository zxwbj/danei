#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//字符串的相关操作，非常重要，必须会
int main(){
  //1 字符串的赋值, = 改地址，strcpy()改值
	char* s1 = "abcd";
	char s2[] = "abcd";//数组是常指针,不能改地址
	char* s3 = malloc(5);
	s1 = "1234";//R
	//strcpy(s1,"1234");//W
	//s2 = "1234";//W
	strcpy(s2,"1234");//R
  //s3 = "1234";//W,有可能导致内存泄露
	strcpy(s3,"1234");//R
  printf("s1=%s,s2=%s,s3=%s\n",s1,s2,s3);
	free(s3);
  //2 字符串的大小和长度
	char buf[100] = { };//buf是数组,也是字符串
  strcpy(buf,"abcd");
  printf("length=%d\n",strlen(buf));//有效长度
	printf("size=%d\n",sizeof(buf));//内存大小
	//3 字符串的比较 == 和 strcmp()
	// ==比较的是指向地址,strcmp()比较的是值
  if(s1 == "1234") printf("s1等于1234\n");
  if(s2 == "1234") printf("s2等于1234\n");
	if(!strcmp(s1,"1234")) printf("s1 1234\n");
	if(!strcmp(s2,"1234")) printf("s2 1234\n");
	//4 字符串的拼接,比如: 路径和文件名拼接
  char* path = "/home/tarena";
	char* filename = "day01.zip";
	char namebuf[100] = {};
	sprintf(namebuf,"%s/%s",path,filename);
	//strcpy(namebuf,path);
	//strcat(namebuf,"/");
  //strcat(namebuf,filename);
	printf("%s\n",namebuf);
	//5 指针操作字符串，字符串以'\0'结束
  char* str = "zhangfei,25";
  char name[20] = {};
	char age[10] = {};
  int i,pos;
  /*int flag = 1;//判断往哪里写数据
	for(i=0;i<strlen(str);i++){
		if(*(str+i) == ','){
		  flag = 0;
			pos = i;
			continue;
		}
	  if(flag){
		  name[i] = *(str+i);//str[i];
		}else{
		  age[i-pos-1] = *(str+i);
		}
	}*/
  for(i=0;i<strlen(str);i++)
		if(*(str+i) == ',') break;
	memcpy(name,str,i);
	memcpy(age,str+i+1,strlen(str)-i-1);
	printf("name=%s:age=%s\n",name,age);
  //6 字符串和int/double的类型转换 sprinf()
  int x = 123,y;
  char xbuf[20] = {};
  sprintf(xbuf,"%d",x);//数值转字符串
	printf("xbuf=%s\n",xbuf);
	sscanf(xbuf,"%d",&y);//字符串转数值
	printf("y=%d\n",y);
} 


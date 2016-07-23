/*
	 结构体演示
	 */
#include <stdio.h>
#include <string.h>
typedef struct /*person*/ {
		int id;
		int age;
		float salary;
} person;
struct phone {
		char manu[20];
		char brand[20];
		char type[10];
		float price;
};
//typedef struct person   person;
//#define    person      struct person
int main() {
		//struct person p;
		person p1;
		struct phone iphone4s;
		strcpy(iphone4s.manu, "Apple");
		strcpy(iphone4s.brand, "IPhone");
		strcpy(iphone4s.type, "4S");
		iphone4s.price = 4000.0f;
		printf("厂商是%s,品牌是%s,型号是%s,价格是%g\n", iphone4s.manu, iphone4s.brand, iphone4s.type, iphone4s.price);
		return 0;
}





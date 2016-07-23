/*
	 人员信息管理系统
	 */
#include <stdio.h>
#include <stdlib.h>
typedef struct {
		int id;
		int age;
		float salary;
} person;
int main() {
    FILE *p_file = fopen("person.bin", "ab");
		person *p_person = NULL;
		int choice = 0;
		if (p_file) {
				p_person = (person*)malloc(sizeof(person));
        if (p_person) {
						do {
								printf("请输入人员id:");
								scanf("%d", &(p_person->id));
								printf("请输入年龄：");
								scanf("%d", &(p_person->age));
								printf("请输入工资：");
								scanf("%g", &(p_person->salary));
								fwrite(p_person, sizeof(person), 1, p_file);
								printf("是否继续输入？0表示不输入，1表示继续");
								scanf("%d", &choice);
								if (!choice) {
										break;
								}
						} while (1);
						free(p_person);
						p_person = NULL;
				}
				fclose(p_file);
				p_file = NULL;
		}
		return 0;
}





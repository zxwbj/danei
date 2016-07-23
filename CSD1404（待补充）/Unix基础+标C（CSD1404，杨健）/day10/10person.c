/*
	 人员信息管理系统练习
	 */
#include <stdio.h>
int main() {
		int id = 0, age = 0, choice = 0;
		float salary = 0.0f;
		FILE *p_file = fopen("person.bin", "wb");
		if (p_file) {
				do {
            printf("请输入id：");
						scanf("%d", &id);
						printf("请输入年龄：");
						scanf("%d", &age);
						printf("请输入工资：");
						scanf("%f", &salary);
						fwrite(&id, sizeof(int), 1, p_file);
						fwrite(&age, sizeof(int), 1, p_file);
						fwrite(&salary, sizeof(float), 1, p_file);
						printf("是否需要输入下一个人员信息？0表示不输入，1表示输入");
						scanf("%d", &choice);
						if (!choice) {
								break;
						}
				} while (1);
				fclose(p_file);
				p_file = NULL;
		}
		return 0;
}

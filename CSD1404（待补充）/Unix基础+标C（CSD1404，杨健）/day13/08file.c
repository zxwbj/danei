/*
	 人员信息管理练习
	 */
#include <stdio.h>
int main() {
		int id = 0, age = 0, choice = 0, oldid = 0;
		float salary = 0.0f;
		FILE *p_file = fopen("person.bin", "a+b");
		if (p_file) {
				do {
            printf("请输入人员id:");
						scanf("%d", &id);
						oldid = -1;
						rewind(p_file);
						while (1) {
                if (!fread(&oldid, sizeof(int), 1, p_file)) {
										break;
								}
								if (oldid == id) {
										break;
								}
								fseek(p_file, 8, SEEK_CUR);
						}
						fseek(p_file, 0, SEEK_END);
						if (oldid == id) {
								continue;
						}
						printf("请输入人员年龄：");
						scanf("%d", &age);
						printf("请输入工资：");
						scanf("%g", &salary);
						fwrite(&id, sizeof(int), 1, p_file);
						fwrite(&age, sizeof(int), 1, p_file);
						fwrite(&salary, sizeof(float), 1, p_file);
						printf("是否输入新的人员信息？1表示输入，0表示不输入");
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

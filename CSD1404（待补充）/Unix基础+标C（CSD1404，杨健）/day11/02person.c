/*
	 人员信息读取作业
	 */
#include <stdio.h>
int main() {
		int id = 0, age = 0;
		float salary = 0.0f;
		FILE *p_file = fopen("person.bin", "rb");
		if (p_file) {
				while (1) {
						if (!fread(&id, sizeof(int), 1, p_file)) {
								break;
						}
						fread(&age, sizeof(int), 1, p_file);
						fread(&salary, sizeof(float), 1, p_file);
						printf("id是%d,年龄是%d,工资是%g\n", id, age, salary);
				}
				fclose(p_file);
				p_file = NULL;
		}
		return 0;
}

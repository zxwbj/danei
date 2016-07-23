/*
	 文件函数演示
	 */
#include <stdio.h>
int main() {
		FILE *p_file = fopen("a.txt", "w");
		/*if (p_file) {
				//
				fclose(p_file);
				p_file = NULL;
		}*/
		if (!p_file) {
				return ;
		}
		//
		fclose(p_file);
		p_file = NULL;
		return 0;
}

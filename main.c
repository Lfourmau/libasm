#include <stdio.h>

int asm_add(int);

int main(){
	int a = 2;
	int b = asm_add(a);

	printf("%d", b);
	return 0;
}
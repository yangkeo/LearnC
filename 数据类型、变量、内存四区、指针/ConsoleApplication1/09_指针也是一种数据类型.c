#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include"stdlib.h"
#include"string.h"

				

int main(void)
{
	int *p = NULL;
	char **********q = NULL;
	int b = 0;
	int a = 100;
	int *p1 = NULL;

	printf("sizeof(p) = %d, sizeof(q) = %d\n", sizeof(p), sizeof(q));
	

	//指针指向谁，就把谁的地址赋值给谁
	p1 = &a;
	//*钥匙，通过*可以找到指针指向的内存区域，操作还是内存
	*p1 = 22;

	b = *p1;
	printf("b = %d, a = %d", b, a);


	printf("\n");
	system("pause");
	return 0;
	
}
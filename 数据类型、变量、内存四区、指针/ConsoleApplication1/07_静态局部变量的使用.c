#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include"stdlib.h"
#include"string.h"

int *getA()
{
	static int a = 10;
	return &a;
}
				

int main(void)
{
	int *p = getA();

	
	
	printf("\n");
	system("pause");
	return 0;
	
}
#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include"stdlib.h"
#include"string.h"

int printf_array(int a[128])
{
	printf("sizeof(a) = %d", sizeof(a));
	return 0;
}
				

int main(void)
{
	int b[128];
	printf_array(b);

	printf("\n");
	system("pause");
	return 0;
	
}